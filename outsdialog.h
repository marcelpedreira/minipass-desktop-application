#ifndef OUTSDIALOG_H
#define OUTSDIALOG_H

#include <QtGui>
#include <QtSql>
#include "ui_doorsdialog.h"

class outsDialog : public QDialog, Ui::doorsDialog
{
    Q_OBJECT
    
public:
    explicit outsDialog(QWidget *parent = 0);
    //~outsDialog();
    
public slots:
    void updateButtons(int row);
    void submit();

private:
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;
};

#endif // OUTSDIALOG_H
