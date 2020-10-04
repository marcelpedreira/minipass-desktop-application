#ifndef DATA_H
#define DATA_H
#include <QtGui>
#include <QtSql/QSqlQuery>
#include <QDateTime>
#include <QStringList>
#include <QStandardItemModel>

class TDataManager
{
public:
    TDataManager();
    bool createConection();
    QList<int> getControllerAddressList();
    QString getControllerType(int controllerAddress);
    QStringList getDoorNameList();  //Devuelve la lista de los nombres de todas las puertas
    QStringList getOutNameList();  //Devuelve la lista de los nombres de todas las salidas
    QString getDoorName(int controllerAddress, int doorPosition);
    QString getInName(int controllerAddress, int inPosition);
    QString getUserName(int userID);
    QString getUserLastName(int userID);
    QList<int> getDoorUserList(int controllerAddress, int doorPosition);    //Devuelve la lista de usuarios (IDs) de acceso a una puerta de un controlador
    QStringList getAccessLevelDoorList(QString accessLevel);    //Devuelve la lista de los nombres de las puertas pertenecientes a un nivel de acceso
    QStringList getActivatedOutList(QString in);
    QDateTime getlastAsk(int controllerAddress);
    bool setlastAsk(QDateTime &lastAsk, int controllerAddress);
    int getAccessLevelID(QString accessLevel);
    bool updateAccessLevelDoorTable(int accessLevelID, QList<int> doorIDList);
    QList<int> getDoorsID(QStringList list);
    int getInID(QString inName);
    bool updateInOutTable(int inID, QList<int> outIDList);
    QList<int> getOutsID(QStringList outNameList);
    QList<int> getInsID(int controllerAddress); //Lista de IDs de entradas ordenada por posicion
    QList<int> getOutsIDRelation(int inID);   //Lista de IDs de las salidas que se activan para cada entrada
    int getOutPosition(int outID);
    //int getUserID(int userCode);
    int getDoorID(int slaveAddr, int doorPosition);
    void saveEvent(QDate eventDate, QTime eventTime, QString eventName, QString location, QString userName, QString userLastName);
    QList<QStringList> getReports(QDateTime initialDate, QDateTime finalDate);
    int getFacCode(int userID);
    int getUserCode(int userID);
};

#endif // DATA_H
