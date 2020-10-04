#ifndef NEWCONTROLLERDIALOG_H
#define NEWCONTROLLERDIALOG_H

#include <QDialog>
#include "ui_newcontrollerdialog.h"

class newControllerDialog : public QDialog, Ui::newControllerDialog
{
    Q_OBJECT
    
public:
    explicit newControllerDialog(QWidget *parent = 0);
    //~newControllerDialog();
    QString getAddress(){return controllerAddressEdit->text();}
    int getType(){return typeComboBox->currentIndex();}
    
private:
    //Ui::newControllerDialog *ui;
};

#endif // NEWCONTROLLERDIALOG_H
