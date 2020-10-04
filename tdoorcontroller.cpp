#include "tdoorcontroller.h"
#include <QDebug>
#include "EIncomplette.h"
//#include "wiegand.h"
#include <QStringList>

TDoorController::TDoorController(modbus_t *mbusPtr, TDataManager *dataManager, int slaveAddr) : TController(mbusPtr, dataManager, slaveAddr)
{

}

void TDoorController::updateUserList()
{
    QList<int> accessLevel_1_userList = dataManager->getDoorUserList(slaveAddr, 1);  //lista de usuarios a la puerta 1
    QList<int> accessLevel_2_userList = dataManager->getDoorUserList(slaveAddr, 2);  //lista de usuarios a la puerta 2

    //Actualizando lista de usuarios de controlador
    QList<int> accessLevel_3_userList;  //lista de usuarios con acceso a ambas puertas
    for(int counter_1 = 0; counter_1 < accessLevel_1_userList.count(); counter_1++){
        for(int counter_2 = 0; counter_2 < accessLevel_2_userList.count(); counter_2++){
            if(accessLevel_1_userList[counter_1] == accessLevel_2_userList[counter_2]){
                accessLevel_3_userList.append(accessLevel_1_userList[counter_1]);
                break;
            }
        }
    }

    //Borrando de las dos primeras listas los usuarios que tienen acceso a ambas puertas
    for(int counter_3 = 0; counter_3 < accessLevel_3_userList.count(); counter_3++){
        accessLevel_1_userList.removeOne(accessLevel_3_userList[counter_3]);
        accessLevel_2_userList.removeOne(accessLevel_3_userList[counter_3]);
    }

    //Actualizando la lista de usuarios
    userList.clear();

    for(int counter = 0; counter < accessLevel_1_userList.count(); counter++){
        TUser user;
        //codeSplit(accessLevel_1_userList[counter], user.facCode, user.userCode);
        user.ID = accessLevel_1_userList[counter];
        user.facCode = dataManager->getFacCode(accessLevel_1_userList[counter]);
        user.userCode = dataManager->getUserCode(accessLevel_1_userList[counter]);
        user.levelAccess = 1;
        userList.append(user);
    }
    for(int counter = 0; counter < accessLevel_2_userList.count(); counter++){
        TUser user;
        //codeSplit(accessLevel_2_userList[counter], user.facCode, user.userCode);
        user.ID = accessLevel_2_userList[counter];
        user.facCode = dataManager->getFacCode(accessLevel_2_userList[counter]);
        user.userCode = dataManager->getUserCode(accessLevel_2_userList[counter]);
        user.levelAccess = 2;
        userList.append(user);
    }
    for(int counter = 0; counter < accessLevel_3_userList.count(); counter++){
        TUser user;
        //codeSplit(accessLevel_3_userList[counter], user.facCode, user.userCode);
        user.ID = accessLevel_3_userList[counter];
        user.facCode = dataManager->getFacCode(accessLevel_3_userList[counter]);
        user.userCode = dataManager->getUserCode(accessLevel_3_userList[counter]);
        user.levelAccess = 3;
        userList.append(user);
    }
}

void TDoorController::update()
{
    updateUserList();

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

    refCnt = userList.count() * 2 + 8;  //Total de registros (16 bits) a enviar (Los codigos mas la fecha, la hora y la cantidad de usuarios)
    uint16_t dataPtr[refCnt];
    dataPtr[0] = concat(minutes, hours);
    dataPtr[1] = concat(date, month);
    dataPtr[2] = concat(year_high, year_low);
    dataPtr[3] = concat(0, userList.count());

    /*qDebug() << minutes;
    qDebug() << hours;
    qDebug() << date;
    qDebug() << month;
    qDebug() << year_high;
    qDebug() << year_low;

    qDebug() << dataPtr[0];
    qDebug() << dataPtr[1];
    qDebug() << dataPtr[2];
    qDebug() << dataPtr[3];*/

    int userCode_low;
    int userCode_high;
    int facCode;
    long userCode;
    int accessLevel;
    int ref = 4;

    for(int counter = 0; counter < userList.count(); counter++){
        facCode = userList[counter].facCode;
        userCode = userList[counter].userCode;
        accessLevel = userList[counter].levelAccess;
        split(userCode, userCode_high, userCode_low);
        dataPtr[ref] = concat(facCode, userCode_high);
        ref++;
        dataPtr[ref] = concat(userCode_low, accessLevel);
        ref++;
    }

    //Escribiendo los datos en el controlador
    for(int i = 0; i < refCnt; i++)
        qDebug() << dataPtr[i];

    modbus_set_slave(mbusPtr, slaveAddr);
    int result = modbus_write_registers(mbusPtr, 0, refCnt, dataPtr);

    qDebug() << "Iteracion";

    if (result != -1)
        qDebug() << "Controlador actualizado";

    /*int result = mbusPtr->writeMultipleRegisters(slaveAddr, 1, (short *) dataPtr, refCnt);
    if (result == FTALK_SUCCESS){
        qDebug() << "Controlador actualizado";
        //return true;
    }*/
}

bool TDoorController::ask(QList<QStringList> &eventList)
{
    updateUserList();

    uint16_t eventCountPtr[1];
    modbus_set_slave(mbusPtr, slaveAddr);
    int result = modbus_read_input_registers(mbusPtr, 0, 1, eventCountPtr);
    if(result == -1){
        qDebug() << "Error en la conexion con el Controlador" << slaveAddr;
        return false;
    }

    /*short eventCountPtr[1];
    int result = mbusPtr->readInputRegisters(slaveAddr, 1, (short *) eventCountPtr, 1);
    if(result != FTALK_SUCCESS){
        qDebug() << "Error en la conexion con el Controlador" << slaveAddr;
        return false;
    }*/

    if(*eventCountPtr == 0)
        return false;   //Nada que encuestar en controlador

    //Limpiando los registros del controlador
    result = modbus_write_bit(mbusPtr, 0, 1);
    if(result == -1){
        qDebug() << "Error en la conexion con el Controlador" << slaveAddr;
        return false;
    }

    /*result = mbusPtr->writeCoil(slaveAddr, 1, 1);
    if(result != FTALK_SUCCESS)
        return false;*/

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

    /*short dataPtr[refCnt];
    result = mbusPtr->readInputRegisters(slaveAddr, 1, (short *) dataPtr, refCnt);
    if(result != FTALK_SUCCESS)
        return false;*/

    //Obteniendo el codigo
    int ref = 1;
    int user, door, minutes, hours, month, year, date, year_low, year_high;
    QString eventName, userName, userLastName, doorString, minutesString, hoursString, monthString, yearString, dateString;

    while(ref < refCnt){
        split(dataPtr[ref], user, minutes);
        ref++;
        split(dataPtr[ref], hours, date);
        ref++;
        split(dataPtr[ref], month, year_high);
        ref++;
        split(dataPtr[ref], year_low, door);
        ref++;
        year = year_high * 100 + year_low;

        switch(user){
            case 255:   //REX
                eventName = "REX concedido";
                userName = "";
                userLastName = "";
                break;
            case 254:   //Acceso denegado
                eventName = "Acceso denegado";
                userName = "";
                userLastName = "";
                break;
            default:
                eventName = "Acceso concedido";
                int userID = userList[user].ID;
                userName = dataManager->getUserName(userID);
                userLastName = dataManager->getUserLastName(userID);
                break;
        }

        QDate eventDate = QDate(year, month, date);
        QTime eventTime = QTime(hours, minutes);

        doorString = dataManager->getDoorName(slaveAddr, door + 1);

        //Imprimiendo el evento en la mainwindow
        QStringList event;
        event.append(dateString.setNum(date) + "/" + monthString.setNum(month) + "/" + yearString.setNum(year));
        event.append(hoursString.setNum(hours) + ":" + minutesString.setNum(minutes));
        event.append(eventName);
        event.append(doorString);
        event.append(userName);
        event.append(userLastName);
        eventList.append(event);

        //Guardando el evento en los registros
        dataManager->saveEvent(eventDate, eventTime, eventName, doorString, userName, userLastName);
    }
    qDebug() << "Exito";
    return true;
}






