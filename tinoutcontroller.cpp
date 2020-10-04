#include "tinoutcontroller.h"
#include <QDebug>
//#include "wiegand.h"

/*long TInOutController::concat(int high, int low)
{
    return (high * 256) + low;
}*/

TInOutController::TInOutController(modbus_t *mbusPtr, TDataManager *dataManager, int slaveAddr) : TController(mbusPtr, dataManager, slaveAddr)
{
    refCnt = 8;
}

void TInOutController::update()
{
    refreshRelation();

    //Actualizando la fecha y hora
    QDateTime temp = QDateTime::currentDateTime();
    int minutes = temp.time().minute();
    int hours = temp.time().hour();
    int date = temp.date().day();
    int month = temp.date().month();
    int year = temp.date().year();
    int year_high;
    int year_low;
    year_split(year, year_high, year_low);

    refCnt = 11;  //Total de registros (16 bits) a enviar (La fecha, la hora y los ocho registros de configuracion)
    uint16_t dataPtr[refCnt];

    dataPtr[0] = concat(minutes, hours);
    dataPtr[1] = concat(date, month);
    dataPtr[2] = concat(year_high, year_low);

    for(int i = 3; i < refCnt; i++)
        dataPtr[i] = concat(0, relationArray[i-3]);

    //Escribiendo los datos en el controlador
    modbus_set_slave(mbusPtr, slaveAddr);
    int result = modbus_write_registers(mbusPtr, 0, refCnt, dataPtr);
    if (result != -1)
        qDebug() << "Controlador actualizado";

}

void TInOutController::refreshRelation()
{
    QList<int> insIDList = dataManager->getInsID(slaveAddr); //Lista de IDs de entradas del controlador en cuestion ordenadas por posicion
    //qDebug() << insIDList;
    QList<int> outsIDRelationArray[8];    //Contiene los IDs de las salidas que se activan para cada entrada

    for(int i = 0; i < 8; i++)
        relationArray[i] = 0;

    for(int i = 0; i < 8; i++){
        outsIDRelationArray[i] = dataManager->getOutsIDRelation(insIDList[i]);
        //qDebug() << outsIDRelationArray[i];
        for(int j = 0; j < outsIDRelationArray[i].count(); j++){
            //qDebug() << dataManager->getOutPosition(outsIDRelationArray[i][j]);
            relationArray[i] += getPonder(dataManager->getOutPosition(outsIDRelationArray[i][j]) - 1);

        }
        //qDebug() << relationArray[i];
    }
}

int TInOutController::getPonder(int position)
{
    int ponder = 1;
    for(int i = 0; i < position; i++)
        ponder *= 2;
    return ponder;
}

bool TInOutController::ask(QList<QStringList> &eventList)
{
    uint16_t eventCountPtr[1];
    modbus_set_slave(mbusPtr, slaveAddr);
    int result = modbus_read_input_registers(mbusPtr, 0, 1, eventCountPtr);
    if(result == -1){
        qDebug() << "Error en la conexion con el Controlador" << slaveAddr;
        return false;
    }

    if(*eventCountPtr == 0)
        return false;   //Nada que encuestar en controlador

    //Limpiando los registros del controlador
    result = modbus_write_bit(mbusPtr, 0, 1);
    if(result == -1){
        qDebug() << "Error en la conexion con el Controlador" << slaveAddr;
        return false;
    }

    //Obteniendo los registros
    refCnt = *eventCountPtr * 4 + 1;

    uint16_t dataPtr[refCnt];
    result = modbus_read_input_registers(mbusPtr, 0, refCnt, dataPtr);
    if(result == -1){
        qDebug() << "Error en la conexion con el Controlador" << slaveAddr;
        return false;
    }

    for(int i = 0; i < refCnt; i++)
        qDebug() << dataPtr[i];

   //Obteniendo el codigo
    int ref = 1;
    int in, action, minutes, hours, month, year, date, year_low, year_high;
    QString inName, actionName, minutesString, hoursString, monthString, yearString, dateString;

    while(ref < refCnt){
        split(dataPtr[ref], in, minutes);
        ref++;
        split(dataPtr[ref], hours, date);
        ref++;
        split(dataPtr[ref], month, year_high);
        ref++;
        split(dataPtr[ref], year_low, action);
        ref++;
        year = year_high * 100 + year_low;

        QDate eventDate = QDate(year, month, date);
        QTime eventTime = QTime(hours, minutes);

        inName = dataManager->getInName(slaveAddr, in + 1);
        if(action == 0)
            actionName = "Entrada activada";
        else
            actionName = "Entrada desactivada";

        //Imprimiendo el evento en la mainwindow
        QStringList event;
        event.append(dateString.setNum(date) + "/" + monthString.setNum(month) + "/" + yearString.setNum(year));
        event.append(hoursString.setNum(hours) + ":" + minutesString.setNum(minutes));
        event.append(actionName);
        event.append(inName);
        event.append("");
        event.append("");
        eventList.append(event);

        //Guardando el evento en los registros
        dataManager->saveEvent(eventDate, eventTime, actionName, inName, "", "");
    }
    qDebug() << "Exito";
    return true;
}
