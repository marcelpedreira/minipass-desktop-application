#ifndef INSDIALOG_H
#define INSDIALOG_H

#include <QtGui>
#include <QtSql>
#include "ui_insdialog.h"
#include "tdatamanager.h"

class insDialog : public QWidget, Ui::insDialog
{
    Q_OBJECT
    
public:
    explicit insDialog(TDataManager *_dataManager, QWidget *parent = 0);
    //~insDialog();
    
    void refreshListWidget();
    void refreshWidget();

private slots:
    void updateButtons(int row);
    void submit();
    void submitDB();
    void revert();
    void addActivatedOut();
    void removeActivatedOut();

private:
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;
    QStringList activatedOutList;
    QStringList outList;
    TDataManager *dataManager;
};

#endif // INSDIALOG_H
