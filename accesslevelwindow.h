#ifndef ACCESSLEVELWINDOW_H
#define ACCESSLEVELWINDOW_H

#include <QtGui>
#include <QtSql>
#include "ui_accesslevelwindow.h"
#include "tdatamanager.h"

class accessLevelWindow : public QWidget, Ui::accessLevelWindow
{
    Q_OBJECT
    
public:
    explicit accessLevelWindow(TDataManager *_dataManager, QWidget *parent = 0);
    //~accessLevelWindow();
    void refreshListWidget();
    void refreshWidget();

private slots:
    void updateButtons(int row);
    void addAccessLevelDoor();
    void removeAccessLevelDoor();
    void submit();
    void submitDB();
    void revert();
    void addAccessLevel();
    void deleteAccessLevel();

private:
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;
    QStringList accessDoorList;
    QStringList doorList;
    TDataManager *dataManager;
};

#endif // ACCESSLEVELWINDOW_H
