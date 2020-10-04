#include "tcontrollermanager.h"
#include "tdoorcontroller.h"
#include "tinoutcontroller.h"
#include <QDebug>
#include "EIncomplette.h"
//#include <modbus/modbus-rtu.h>

TControllerManager::TControllerManager(TDataManager *_dataManager)
{
    dataManager = _dataManager;
    model = new QStandardItemModel;
    QStringList labels;
    labels.append("Fecha");
    labels.append("Hora");
    labels.append("Evento");
    labels.append("Lugar");
    labels.append("Nombre");
    labels.append("Apellido");
    model->setHorizontalHeaderLabels(labels);

}

TControllerManager::~TControllerManager()
{
    if(this->isRunning()){
        disconectSystem();
        //delete mbusPtr;
    }
}

void TControllerManager::refreshControllerList()
{
    controllerList.clear();
    controllerAddressList = dataManager->getControllerAddressList();
    for(int i = 0; i < controllerAddressList.count(); i++){
        TController* controller;
        if(dataManager->getControllerType(controllerAddressList[i]) == "doors")
            controller = new TDoorController(mbusPtr, dataManager, controllerAddressList[i]);
        else
            controller = new TInOutController(mbusPtr, dataManager, controllerAddressList[i]);
        controllerList.append(controller);
    }
}

void TControllerManager::run()
{
    int pollCount = 0;
    while(!stopThreads){
        refreshControllerList();
        controllerCount = 0;
        for(int i = 0; i < controllerAddressList.count(); i++){
            QList<QStringList> eventList;
            controllerList[i]->checkConexion();
            if(controllerList[i]->isConected())
                controllerCount++;
            if(controllerList[i]->ask(eventList)){
                for(int i = 0; i < eventList.count(); i++)
                    addLine(eventList[i]);
            }
            if(stopThreads)
                break;
        }
        sleep(1);
        pollCount++;
        qDebug() << "poll" << pollCount;
        //emit pollFinish(controllerCount);
    }
}

bool TControllerManager::conectSystem()
{
    //mbusPtr = new MbusRtuMasterProtocol();

    if(!systemConected){
        mbusPtr = modbus_new_rtu(portName, 9600, 'N', 8, 1);
        if (mbusPtr == NULL) {
            qDebug() << "Configuration setting not supported!\n";
            return false;
        }

        modbus_connect(mbusPtr);
        systemConected = true;
        qDebug() << "Sistema conectado";
        updateSystem();
        this->start();
    }
    return true;

    /*int result = ((MbusRtuMasterProtocol *) mbusPtr)->openProtocol((char *) portName, 9600, 8, 1, 0);
    switch (result)
       {
          case FTALK_SUCCESS:
             systemConected = true;
             qDebug() << "Sistema conectado";
             updateSystem();
             //stopThreads = false;
             this->start();

          return true;
          //break;
          case FTALK_ILLEGAL_ARGUMENT_ERROR:
             qDebug() << "Configuration setting not supported!\n";
             exit(EXIT_FAILURE);
          break;
          case FTALK_TCPIP_CONNECT_ERR:
             qDebug() << "Can't reach server/slave! Check TCP/IP and firewall settings.\n";
             exit(EXIT_FAILURE);
          break;
          default:
             qDebug() << getBusProtocolErrorText(result);
             //throw EIncomplette(getBusProtocolErrorText(result));
             exit(EXIT_FAILURE);
          break;
       }
    return false;*/
}

void TControllerManager::disconectSystem()
{
    //((MbusSerialMasterProtocol *) mbusPtr)->closeProtocol();

     stop();
     qDebug() << "Sistema desconectado";
     if(this->isRunning())
        wait();
     modbus_close(mbusPtr);
     modbus_free(mbusPtr);
}

void TControllerManager::updateSystem()
{
    refreshControllerList();
    for(int i = 0; i < controllerAddressList.count(); i++){
        controllerList[i]->checkConexion();
        if(controllerList[i]->isConected())
            controllerList[i]->update();
    }
}

void TControllerManager::updateSystemSlot()
{
    stop();
    if(this->isRunning())
        wait();

    if(systemConected)
        updateSystem();
    else
        qDebug() << "Sistema desconectado";

    restart();
    if(!this->isRunning())
        start();
}

void TControllerManager::addLine(QStringList event)
{
    QList<QStandardItem *> items;
    for(int i = 0; i < event.count(); i++){
        QStandardItem *item = new QStandardItem(event[i]);
        items.append(item);

    }
    model->appendRow(items);
}

QString TControllerManager::getControllerStatus(int controllerAddress)
{
    if(controllerList[controllerAddressList.indexOf(controllerAddress)]->isConected())
        return "Conectado";
    return "Desconectado";
}

