#include "newcontrollerdialog.h"


newControllerDialog::newControllerDialog(QWidget *parent) :  QDialog(parent)
{
    setupUi(this);
    QValidator *addressValidator = new QIntValidator(1, 31, this);
    controllerAddressEdit->setValidator(addressValidator);
}

