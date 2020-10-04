/********************************************************************************
** Form generated from reading UI file 'newcontrollerdialog.ui'
**
** Created: Fri May 16 13:52:45 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCONTROLLERDIALOG_H
#define UI_NEWCONTROLLERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_newControllerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QComboBox *typeComboBox;
    QLineEdit *controllerAddressEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *newControllerDialog)
    {
        if (newControllerDialog->objectName().isEmpty())
            newControllerDialog->setObjectName(QString::fromUtf8("newControllerDialog"));
        newControllerDialog->resize(258, 137);
        verticalLayout = new QVBoxLayout(newControllerDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(newControllerDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(newControllerDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        typeComboBox = new QComboBox(newControllerDialog);
        typeComboBox->setObjectName(QString::fromUtf8("typeComboBox"));

        gridLayout->addWidget(typeComboBox, 1, 1, 1, 1);

        controllerAddressEdit = new QLineEdit(newControllerDialog);
        controllerAddressEdit->setObjectName(QString::fromUtf8("controllerAddressEdit"));

        gridLayout->addWidget(controllerAddressEdit, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(newControllerDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        retranslateUi(newControllerDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), newControllerDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newControllerDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(newControllerDialog);
    } // setupUi

    void retranslateUi(QDialog *newControllerDialog)
    {
        newControllerDialog->setWindowTitle(QApplication::translate("newControllerDialog", "Nuevo controlador", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("newControllerDialog", "Direccion:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("newControllerDialog", "Tipo:", 0, QApplication::UnicodeUTF8));
        typeComboBox->clear();
        typeComboBox->insertItems(0, QStringList()
         << QApplication::translate("newControllerDialog", "SDC", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class newControllerDialog: public Ui_newControllerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCONTROLLERDIALOG_H
