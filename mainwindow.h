#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "tcontrollermanager.h"
#include "accesslevelwindow.h"
#include "insdialog.h"
#include "reportwindow.h"
#include "controllersdialog.h"
#include "userswindow.h"

class MainWindow : public QMainWindow, Ui::MainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    accessLevelWindow *myAccessLevelWindow;
    insDialog *myInWindow;
    ReportWindow *myReportWindow;
    usersWindow *myUserWindow;
    TDataManager *dataManager;
    TControllerManager *controllerManager;
    QLabel* conexionStatusBarLabel;
    QLabel* controllersStatusBarLabel;
    controllersDialog* dialog;

public slots:
    bool autenticate();
    void init();
    void updateControllerStatus(int controllerAddress);
    void showControllersWindow();
    void showAccessLevelWindow();
    void showUsersWindow();
    void showEventWindow();
    void showDoorsWindow();
    void showInsWindow();
    void showOutsWindow();
    void systemUpdate();
    void cleanEvents();
    void conectSystem();
    void aboutClick();
};

#endif // MAINWINDOW_H
