#include "mainwindow.h"
#include "doorsdialog.h"
#include "insdialog.h"
#include "outsdialog.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    connect(actionControladores, SIGNAL(activated()), this, SLOT(showControllersWindow()));
    connect(actionNiveles_de_acceso, SIGNAL(activated()), this, SLOT(showAccessLevelWindow()));
    connect(actionUsuarios, SIGNAL(activated()), this, SLOT(showUsersWindow()));
    connect(actionRegistros, SIGNAL(activated()), this, SLOT(showEventWindow()));
    connect(actionLimpiar_eventos, SIGNAL(activated()), this, SLOT(cleanEvents()));
    connect(actionPuertas, SIGNAL(activated()), this, SLOT(showDoorsWindow()));
    connect(actionEntradas, SIGNAL(activated()), this, SLOT(showInsWindow()));
    connect(actionSalidas, SIGNAL(activated()), this, SLOT(showOutsWindow()));
    connect(actionSystemUpdate, SIGNAL(activated()), this, SLOT(systemUpdate()));
    connect(actionSobre, SIGNAL(activated()), this, SLOT(aboutClick()));
    conexionStatusBarLabel = new QLabel;
    conexionStatusBarLabel->setText("Estado: Desconectado");
    controllersStatusBarLabel = new QLabel;
    //QMainWindow::statusBar()->addPermanentWidget(conexionStatusBarLabel, 1);
    QMainWindow::statusBar()->addPermanentWidget(controllersStatusBarLabel);
    controllersStatusBarLabel->setText("Sistema desconectado");
}

MainWindow::~MainWindow()
{
    delete myAccessLevelWindow;
    delete myInWindow;
    delete myReportWindow;
    delete myUserWindow;
    delete controllerManager;
    delete dataManager;
    delete dialog;
}

bool MainWindow::autenticate()
{
    return dataManager->createConection();
}

void MainWindow::init()
{
    dataManager = new TDataManager();
    dialog = new controllersDialog(this);
    controllerManager = new TControllerManager(dataManager);
    myAccessLevelWindow = new accessLevelWindow(dataManager);
    myInWindow = new insDialog(dataManager);
    myReportWindow = new ReportWindow(dataManager);
    myUserWindow = new usersWindow();
    tableView->setModel(controllerManager->model);
    conectSystem();
    connect(dialog, SIGNAL(controllerChanged(int)), this, SLOT(updateControllerStatus(int)));
    connect(actionConectar_sistema, SIGNAL(activated()), this, SLOT(conectSystem()));

}

void MainWindow::conectSystem()
{
    if(controllerManager->conectSystem())
        controllersStatusBarLabel->setText("Sistema conectado");
}

void MainWindow::showControllersWindow()
{
    //controllersDialog dlg(this);
    dialog->exec();
}

void MainWindow::showAccessLevelWindow()
{
    myAccessLevelWindow->show();
}

void MainWindow::showUsersWindow()
{
    myUserWindow->show();
}

void MainWindow::showEventWindow()
{
    myReportWindow->show();
}

void MainWindow::showDoorsWindow()
{
    doorsDialog dlg(this);
    dlg.exec();
}

void MainWindow::showOutsWindow()
{
    outsDialog dlg(this);
    dlg.exec();
}

void MainWindow::showInsWindow()
{
    myInWindow->show();
}

void MainWindow::systemUpdate()
{
    controllerManager->updateSystemSlot();
}

void MainWindow::cleanEvents()
{
    controllerManager->model->clear();
}

void MainWindow::updateControllerStatus(int controllerAddress)
{
    dialog->updateControllerStatus(controllerManager->getControllerStatus(controllerAddress));
}

void MainWindow::aboutClick()
{
    QMessageBox::about(     this,
                            tr("MiniPass"),
                            tr("MiniPass v1.0\nCreado por Marcel Pedreira Marcel\nemail:marcel@cim.sld.cu"));
}
