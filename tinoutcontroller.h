#ifndef TINOUTCONTROLLER_H
#define TINOUTCONTROLLER_H

#include "tcontroller.h"
#include <QList>
#include <QStringList>
#include <modbus/modbus.h>

class TInOutController : public TController
{
public:
    TInOutController(modbus_t *mbusPtr, TDataManager *dataManager, int slaveAddr);
    void update();
    void refreshRelation();
    int getPonder(int position);
    //long concat(int high, int low);
    bool ask(QList<QStringList> &eventList);

private:
    int relationArray[8];
};

#endif // TINTERLOCKCONTROLLER_H
