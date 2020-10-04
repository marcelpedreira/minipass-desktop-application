#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if(!w.autenticate()){
        //QMessageBox::information(0,"Error",QSqlDatabase::database().lastError().text());
        QMessageBox::critical(0,"Error", "No se puede iniciar la aplicacion");
        return 1;
    }
    w.show();
    w.init();
    return a.exec();
}
