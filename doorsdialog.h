#ifndef DOORSDIALOG_H
#define DOORSDIALOG_H

#include <QtGui>
#include <QtSql>
#include "ui_doorsdialog.h"

class doorsDialog : public QDialog, Ui::doorsDialog
{
    Q_OBJECT
    
public:
    explicit doorsDialog(QWidget *parent = 0);
    //~doorsDialog();

public slots:
    void updateButtons(int row);
    void submit();
    
private:
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;
};

#endif // DOORSDIALOG_H
