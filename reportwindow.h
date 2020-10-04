#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H

#include <QtGui>
#include <QtSql>
#include "ui_reportwindow.h"
#include "tdatamanager.h"

class ReportWindow : public QMainWindow, Ui::ReportWindow
{
    Q_OBJECT
    
public:
    explicit ReportWindow(TDataManager *_dataManager, QWidget *parent = 0);
    //~ReportWindow();
    
private:
    //QSqlRelationalTableModel *model;
    TDataManager *dataManager;
    QList<QStringList> reports;
    QStringList tableLabels;

public slots:
    void generateReports();
    void printReports();
};

#endif // REPORTWINDOW_H
