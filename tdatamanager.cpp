#include "tdatamanager.h"
#include <QtSql/QSqlDatabase>
#include <QVariant>
#include <QDebug>
#include <QtSql/QSqlError>

TDataManager::TDataManager()
{
}

bool TDataManager::createConection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("MiniPassDB");
    db.setUserName("root");
    db.setPassword(QInputDialog::getText(0,"MiniPass","Password:",QLineEdit::Password));

    if (!db.open()) {
        qDebug() << db.lastError();
        return false;
    }

    db.exec("use testDB");
    db.exec("CREATE TABLE IF NOT EXISTS controllers (controllerAddress int unsigned not null PRIMARY KEY, controllerType char(30))");
    db.exec("CREATE TABLE IF NOT EXISTS ins (inID int unsigned not null auto_increment PRIMARY KEY, controllerAddress int unsigned, position int unsigned not null, name char(30), index(controllerAddress), foreign key(controllerAddress) references controllers(controllerAddress) on delete cascade)");
    db.exec("CREATE TABLE IF NOT EXISTS outs (outID int unsigned not null auto_increment PRIMARY KEY, controllerAddress int unsigned, position int unsigned not null, name char(30), index(controllerAddress), foreign key(controllerAddress) references controllers(controllerAddress) on delete cascade)");
    db.exec("CREATE TABLE IF NOT EXISTS in_outs (inID int unsigned not null, outID int unsigned not null, PRIMARY KEY(inID, outID), index(inID, outID), foreign key(inID) references ins(inID) on delete cascade, foreign key(outID) references outs(outID) on delete cascade)");
    db.exec("CREATE TABLE IF NOT EXISTS doors (doorID int unsigned not null auto_increment PRIMARY KEY, controllerAddress int unsigned, position int unsigned not null, name char(30), index(controllerAddress), foreign key(controllerAddress) references controllers(controllerAddress) on delete cascade)");
    db.exec("CREATE TABLE IF NOT EXISTS accessLevels (accessLevelID int unsigned not null auto_increment PRIMARY KEY, name char(30))");
    db.exec("CREATE TABLE IF NOT EXISTS accessLevels_doors (accessLevelID int unsigned not null, doorID int unsigned not null, PRIMARY KEY(accessLevelID, doorID), index(accessLevelID, doorID), foreign key(accessLevelID) references accessLevels(accessLevelID) on delete cascade, foreign key(doorID) references doors(doorID) on delete cascade)");
    db.exec("CREATE TABLE IF NOT EXISTS users (userID int unsigned not null PRIMARY KEY, accessLevelID int unsigned, name char(30), lastName char(30), facilityCode int unsigned, userCode int unsigned, index(accessLevelID), foreign key(accessLevelID) references accessLevels(accessLevelID))");
    db.exec("CREATE TABLE IF NOT EXISTS eventReports(eventDate date, eventTime time, eventName char(30), location char(30), userName char(30), userLastName char(30))");

    return true;
}

QList<int> TDataManager::getControllerAddressList()
{
     QSqlQuery query;
     if(!query.exec("SELECT controllerAddress FROM controllers")){
         qDebug() << query.lastError();
         //return false;
     }

     QList<int> list;
     while(query.next())
            list.append(query.value(0).toInt());

     //qDebug() << list;
     return list;
}

QString TDataManager::getControllerType(int controllerAddress)
{
    QSqlQuery query;
    query.prepare("SELECT controllerType FROM controllers WHERE controllerAddress = :controllerAddress");
    query.bindValue(":controllerAddress", controllerAddress);

    if(!query.exec()){
        qDebug() << query.lastError();
        //return false;
    }

    query.next();
    return query.value(0).toString();
}

QList<int> TDataManager::getDoorUserList(int controllerAddress, int doorPosition)
{
    QSqlQuery query;
    query.prepare("SELECT users.userID FROM users, doors, accessLevels, accessLevels_doors WHERE doors.controllerAddress = :controllerAddress AND doors.position = :doorPosition and accessLevels_doors.doorID = doors.doorID and accessLevels_doors.accessLevelID = accessLevels.accessLevelID and accessLevels.accessLevelID = users.accessLevelID");
    query.bindValue(":controllerAddress", controllerAddress);
    query.bindValue(":doorPosition", doorPosition);

    if(!query.exec()){
        qDebug() << query.lastError();
        //return false;
    }

    QList<int> list;
    while(query.next())
        list.append(query.value(0).toInt());

    //qDebug() << list;
    return list;
}

int TDataManager::getFacCode(int userID)
{
    QSqlQuery query;
    query.prepare("SELECT facilityCode FROM users WHERE userID = :userID");
    query.bindValue(":userID", userID);

    if(!query.exec()){
        qDebug() << query.lastError();
        //return false;
    }

    query.next();
    return query.value(0).toInt();
}

int TDataManager::getUserCode(int userID)
{
    QSqlQuery query;
    query.prepare("SELECT userCode FROM users WHERE userID = :userID");
    query.bindValue(":userID", userID);

    if(!query.exec()){
        qDebug() << query.lastError();
        //return false;
    }

    query.next();
    return query.value(0).toInt();
}

QString TDataManager::getDoorName(int controllerAddress, int doorPosition)
{
    QSqlQuery query;
    query.prepare("SELECT name FROM doors WHERE controllerAddress = :controllerAddress AND position = :doorPosition");
    query.bindValue(":controllerAddress", controllerAddress);
    query.bindValue(":doorPosition", doorPosition);

    if(!query.exec()){
        qDebug() << query.lastError();
        //return false;
    }

    query.next();
    return query.value(0).toString();
}

QString TDataManager::getInName(int controllerAddress, int inPosition)
{
    QSqlQuery query;
    query.prepare("SELECT name FROM ins WHERE controllerAddress = :controllerAddress AND position = :inPosition");
    query.bindValue(":controllerAddress", controllerAddress);
    query.bindValue(":inPosition", inPosition);

    if(!query.exec()){
        qDebug() << query.lastError();
        //return false;
    }

    query.next();
    return query.value(0).toString();
}

QString TDataManager::getUserName(int userID)
{
    QSqlQuery query;
    query.prepare("SELECT name FROM users WHERE userID = :userID");
    query.bindValue(":userID", userID);

    if(!query.exec()){
        qDebug() << query.lastError();
        //return false;
    }

    query.next();
    return query.value(0).toString();
}

QString TDataManager::getUserLastName(int userID)
{
    QSqlQuery query;
    query.prepare("SELECT lastName FROM users WHERE userID = :userID");
    query.bindValue(":userID", userID);

    if(!query.exec()){
        qDebug() << query.lastError();
        //return false;
    }

    query.next();
    return query.value(0).toString();
}

 QDateTime TDataManager::getlastAsk(int controllerAddress)
 {
     QSqlQuery query;
     query.prepare("SELECT lastAsk FROM controllers WHERE controllerAddress = :controllerAddress");
     query.bindValue(":controllerAddress", controllerAddress);

     if(!query.exec()){
         qDebug() << query.lastError();
         //return false;
     }

     QString lastAskStr;
     QDateTime lastAsk;
     query.next();
     lastAskStr = query.value(0).toString();
     qDebug() << "lastAskStr" << lastAskStr;
     if(lastAskStr == "NULL")
         lastAsk = QDateTime(QDate(0,0,0), QTime(0,0));
     else
         lastAsk = QDateTime::fromString(lastAskStr, "yyyy-MM-dd'T'hh:mm:ss");

     return lastAsk;
 }

 bool TDataManager::setlastAsk(QDateTime &lastAsk, int controllerAddress)
 {
     QSqlQuery query;
     QString lastAskStr = lastAsk.toString("yyyy-MM-dd hh:mm:ss");
     qDebug() << "lastAskStr desde setLastAsk" << lastAskStr;

     query.prepare("UPDATE controllers SET lastAsk = :lastAsk WHERE controllerAddress = :controllerAddress");
     query.bindValue(":lastAsk", lastAskStr);
     query.bindValue(":controllerAddress", controllerAddress);

     if(!query.exec()){
         qDebug() << query.lastError();
         return false;
     }

     return true;
 }

 QStringList TDataManager::getAccessLevelDoorList(QString accessLevel)
 {
    QSqlQuery query;
    query.prepare("SELECT doors.name FROM accessLevels, accessLevels_doors, doors WHERE accessLevels.name = :name AND accessLevels.accessLevelID = accessLevels_doors.accessLevelID AND accessLevels_doors.doorID = doors.doorID");
    query.bindValue(":name", accessLevel);

    if(!query.exec())
        qDebug() << query.lastError();

    QStringList list;
    while(query.next())
        list.append(query.value(0).toString());

    return list;
 }

 QStringList TDataManager::getActivatedOutList(QString in)
 {
    QSqlQuery query;
    query.prepare("SELECT outs.name FROM outs, in_outs, ins WHERE ins.name = :name AND ins.inID = in_outs.inID AND in_outs.outID = outs.outID");
    query.bindValue(":name", in);

    if(!query.exec())
        qDebug() << query.lastError();

    QStringList list;
    while(query.next())
        list.append(query.value(0).toString());

    return list;
 }

 QStringList TDataManager::getDoorNameList()
 {
     QSqlQuery query;
     query.prepare("SELECT name FROM doors");

     if(!query.exec())
         qDebug() << query.lastError();

     QStringList list;
     while(query.next())
         list.append(query.value(0).toString());

     return list;
 }

 QStringList TDataManager::getOutNameList()
 {
     QSqlQuery query;
     query.prepare("SELECT name FROM outs");

     if(!query.exec())
         qDebug() << query.lastError();

     QStringList list;
     while(query.next())
         list.append(query.value(0).toString());

     return list;
 }

QList<int> TDataManager::getDoorsID(QStringList list)
 {
     QSqlQuery query;
     QList<int> IDList;

     for(int i = 0; i < list.count(); i++){
         query.prepare("SELECT doorID FROM doors WHERE name = :doorName");
         query.bindValue(":doorName", list[i]);

         if(!query.exec())
             qDebug() << query.lastError();

         query.next();
         IDList.append(query.value(0).toInt());

     }
     return IDList;
 }

 int TDataManager::getAccessLevelID(QString accessLevel)
 {
    QSqlQuery query;
    query.prepare("SELECT accessLevelID FROM accessLevels WHERE name = :accessLevel");
    query.bindValue(":accessLevel", accessLevel);

    if(!query.exec())
        qDebug() << query.lastError();

    query.next();
    return query.value(0).toInt();
 }

 bool TDataManager::updateAccessLevelDoorTable(int accessLevelID, QList<int> doorIDList)
 {
     QSqlQuery query;
     query.prepare("delete FROM accessLevels_doors WHERE accessLevelID = :accessLevelID");
     query.bindValue(":accessLevelID", accessLevelID);

     if(!query.exec()){
         qDebug() << query.lastError();
         return false;
     }

     for(int i = 0; i < doorIDList.count(); i++){
         query.prepare("insert into accessLevels_doors values (:accessLevelID, :doorID)");
         query.bindValue(":doorID", doorIDList[i]);
         query.bindValue(":accessLevelID", accessLevelID);

         if(!query.exec()){
             qDebug() << query.lastError();
             return false;
         }
     }

     return true;
 }

 int TDataManager::getInID(QString inName)
 {
    QSqlQuery query;
    query.prepare("SELECT inID FROM ins WHERE name = :inName");
    query.bindValue(":inName", inName);

    if(!query.exec())
        qDebug() << query.lastError();

    query.next();
    return query.value(0).toInt();
 }

 bool TDataManager::updateInOutTable(int inID, QList<int> outIDList)
 {
     QSqlQuery query;
     query.prepare("delete FROM in_outs WHERE inID = :inID");
     query.bindValue(":inID", inID);

     if(!query.exec()){
         qDebug() << query.lastError();
         return false;
     }

     for(int i = 0; i < outIDList.count(); i++){
         query.prepare("insert into in_outs values (:inID, :outID)");
         query.bindValue(":outID", outIDList[i]);
         query.bindValue(":inID", inID);

         if(!query.exec()){
             qDebug() << query.lastError();
             return false;
         }
     }

     return true;
 }

 QList<int> TDataManager::getOutsID(QStringList outNameList)
 {
     QSqlQuery query;
     QList<int> IDList;

     for(int i = 0; i < outNameList.count(); i++){
         query.prepare("SELECT outID FROM outs WHERE name = :outName");
         query.bindValue(":outName", outNameList[i]);

         if(!query.exec())
             qDebug() << query.lastError();

         query.next();
         IDList.append(query.value(0).toInt());

     }
     return IDList;
 }

 QList<int> TDataManager::getInsID(int controllerAddress)
 {
     QSqlQuery query;
     QList<int> IDList;

     for(int i = 1; i <= 8; i++){
         query.prepare("SELECT inID FROM ins WHERE position = :position AND controllerAddress = :controllerAddress");
         query.bindValue(":position", i);
         query.bindValue(":controllerAddress", controllerAddress);

         if(!query.exec())
             qDebug() << query.lastError();

         query.next();
         IDList.append(query.value(0).toInt());

     }
     return IDList;
 }

 QList<int> TDataManager::getOutsIDRelation(int inID)
 {
     QSqlQuery query;
     QList<int> IDList;

     query.prepare("SELECT outID FROM in_outs WHERE inID = :inID");
     query.bindValue(":inID", inID);

     if(!query.exec())
         qDebug() << query.lastError();

     while(query.next())
         IDList.append(query.value(0).toInt());

     return IDList;
 }

 int TDataManager::getOutPosition(int outID)
 {
    QSqlQuery query;

    query.prepare("SELECT position FROM outs WHERE outID = :outID");
    query.bindValue(":outID", outID);

    if(!query.exec())
        qDebug() << query.lastError();

    query.next();
    return query.value(0).toInt();
 }

 /*int TDataManager::getUserID(int userCode)
 {
     QSqlQuery query;
     query.prepare("SELECT userID FROM users WHERE code = :userCode");
     query.bindValue(":userCode", userCode);

     if(!query.exec()){
         qDebug() << query.lastError();
         //return false;
     }

     query.next();
     return query.value(0).toInt();
 }*/

 int TDataManager::getDoorID(int controllerAddress, int doorPosition)
 {
     QSqlQuery query;
     query.prepare("SELECT doorID FROM doors WHERE controllerAddress = :controllerAddress AND position = :doorPosition");
     query.bindValue(":controllerAddress", controllerAddress);
     query.bindValue(":doorPosition", doorPosition);

     if(!query.exec()){
         qDebug() << query.lastError();
         //return false;
     }

     query.next();
     return query.value(0).toInt();
 }

 void TDataManager::saveEvent(QDate eventDate, QTime eventTime, QString eventName, QString location, QString userName, QString userLastName)
 {
     QSqlQuery query;
     QString eventDateStr = eventDate.toString("yyyy-MM-dd");
     QString eventTimeStr = eventTime.toString("hh:mm:ss");

     query.prepare("INSERT INTO eventReports values (:eventDate, :eventTime, :eventName, :location, :userName, :userLastName)");
     query.bindValue(":eventDate", eventDateStr);
     query.bindValue(":eventTime", eventTimeStr);
     query.bindValue(":eventName", eventName);
     query.bindValue(":location", location);
     query.bindValue(":userName", userName);
     query.bindValue(":userLastName", userLastName);

     if(!query.exec()){
         qDebug() << query.lastError();
         //return false;
     }

     //return true;
 }

QList<QStringList> TDataManager::getReports(QDateTime initialDate, QDateTime finalDate)
 {
    QString initialDateStr = initialDate.date().toString("yyyy-MM-dd");
    QString initialTimeStr = initialDate.time().toString("hh:mm:ss");
    QString finalDateStr = finalDate.date().toString("yyyy-MM-dd");
    QString finalTimeStr = finalDate.time().toString("hh:mm:ss");

    QSqlQuery query;
     query.prepare("select * from eventReports where eventDate >= :initialDate and eventDate <= :finalDate and eventTime >= :initialTime and eventTime <= :finalTime");
     query.bindValue(":initialDate", initialDateStr);
     query.bindValue(":finalDate", finalDateStr);
     query.bindValue(":initialTime", initialTimeStr);
     query.bindValue(":finalTime", finalTimeStr);

     if(!query.exec())
         qDebug() << query.lastError();

     QList<QStringList> eventList;

     while(query.next()){
         QStringList event;
         for(int i = 0; i < 6; i++)
             event.append(query.value(i).toString());
         eventList.append(event);
     }

     return eventList;
 }
