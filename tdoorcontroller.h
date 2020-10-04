#ifndef TDOORCONTROLLER_H
#define TDOORCONTROLLER_H

#include "tcontroller.h"
#include <QList>
#include <modbus/modbus.h>

struct TUser
{
    int ID;
    int facCode;
    int userCode;
    int levelAccess;
};

class TDoorController : public TController
{
public:
    TDoorController(modbus_t *mbusPtr, TDataManager *dataManager, int slaveAddr);
    void update();
    bool ask(QList<QStringList> &eventList);
    void updateUserList();

private:
    QList<TUser> userList;  //lista de usuarios del controlador con sus codigos y niveles de acceso
};

#endif // TDOORCONTROLLER_H
