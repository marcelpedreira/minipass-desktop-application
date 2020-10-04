#ifndef CONTROLLERSDIALOG_H
#define CONTROLLERSDIALOG_H

#include <QtGui>
#include <QtSql>
//#include "ui_controllersdialog.h"
#include "ui_doorsdialog.h"

class controllersDialog : public QDialog, Ui::doorsDialog
{
    Q_OBJECT
    
public:
    explicit controllersDialog(QWidget *parent = 0);
    //~controllersDialog();

public slots:
    void updateButtons(int row);
    void submit();
    void addController();
    void deleteController();
    void updateControllerStatus(QString Status);

private:
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;

signals:
    void controllerChanged(int controllerAddress);
};

#endif // CONTROLLERSDIALOG_H
