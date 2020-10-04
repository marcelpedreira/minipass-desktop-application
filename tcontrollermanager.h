#ifndef TMANAGER_H
#define TMANAGER_H
#include "tdatamanager.h"
//#include <QThread>
#include "tcontroller.h"
#include <QtSql>
#include <QStandardItemModel>
#include <modbus.h>

//class TControllerManager : public QThread
class TControllerManager
{
    //Q_OBJECT

public:
    TControllerManager(TDataManager *_dataManager);
    /*~TControllerManager();
    void run();
    void stop(){stopThreads = true;}
    void restart(){stopThreads = false;}
    void addLine(QStringList event);
    bool isSystemConected(){return systemConected;}
    QString getControllerStatus(int controllerAddress);*/
    QStandardItemModel *model;

/*public slots:
    void changeAccessLevelDoorList(QString accessLevel);
    void newController(int address);
    bool conectSystem();
    void disconectSystem();
    void updateSystemSlot();
    void refreshControllerList();
    int getControllerCount(){return controllerCount;}*/
    void updateSystem();

private:
    TDataManager *dataManager;
    modbus_t *mbusPtr;
    char *portName = "/dev/ttyS0";
    //QList<int> controllerAddressList;
    QList<TController*> controllerList;
    //TController* controllerArray[10];
    //bool stopThreads = false;
    //TController *controller;
    //int controllerCount = 0;
    //bool systemConected = false;

//signals:
    //void pollFinish(int conectedConectedControllerCount);
};

#endif // TMANAGER_H
