#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <modbus.h>
#include "tdatamanager.h"
#include <QDateTime>
//#include "wiegand.h"

// HM platform detection
//#include "hmplatf.h"

// Platform header
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

class TController
{
public:
    TController(modbus_t *mbusPtr = 0, TDataManager *dataManager = 0, int slaveAddr = 0);
    //TController(const TController &c);
    int getAddress(){return slaveAddr;}
    virtual void update() = 0;
    /*virtual bool ask(QList<QStringList> &eventList) = 0;
    bool isConected(){return conected;}
    void setConexionStatus(bool status){conected = status;}
    void checkConexion();
    void codeSplit(int code, int &facCode, int &userCode);
    int codeConcat(int facCode, int userCode);
    long concat(int high, int low);
    void split(long number, int &high, int &low);
    void year_split(int year, int &year_high, int &year_low);*/

protected:
    //MbusMasterFunctions *mbusPtr;   //Puntero a la conexion serie para hacer update
    modbus_t *mbusPtr;
    TDataManager *dataManager;  //Puntero a la base de datos para conformar la data a pasar
    int slaveAddr;
    //int refCnt = 64; //cantidad de registros a leer
    //bool conected = false;
};

#endif // CONTROLLER_H
