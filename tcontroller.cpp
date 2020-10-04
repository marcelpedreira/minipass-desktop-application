#include <QDebug>
#include "tcontroller.h"
#include "EIncomplette.h"

TController::TController(modbus_t *_mbusPtr, TDataManager *_dataManager, int _slaveAddr)
{
    slaveAddr = _slaveAddr;
    mbusPtr = _mbusPtr;
    dataManager = _dataManager;
}

void TController::checkConexion()
{
    //short dataPtr[1];
    uint16_t dataPtr[1];
    modbus_set_slave(mbusPtr, slaveAddr);
    int result = modbus_read_registers(mbusPtr, 0, 1, dataPtr);
    if (result == -1)
        conected = false;
    else
        conected = true;

    /*int result = mbusPtr->readMultipleRegisters(slaveAddr, 1, (short *) dataPtr, 1);
    if(result != FTALK_SUCCESS){
        qDebug() << "Error en la conexion con el Controlador" << slaveAddr;
        conected = false;
    }
    else
        conected = true;*/
}

void TController::codeSplit(int code, int &facCode, int &userCode)
{
    facCode = code / 100000;
    userCode = code % 100000;
}

int TController::codeConcat(int facCode, int userCode)
{
    return (facCode * 100000) + userCode;
}


long TController::concat(int high, int low)
{
    return (high * 256) + low;
}

void TController::split(long number, int &high, int &low)
{
    low = number & 255;
    long temp = number & 0b1111111100000000;
    high = temp / 256;
}

void TController::year_split(int year, int &year_high, int &year_low)
{
        year_high = year / 100;
        year_low = year % 100;
}










