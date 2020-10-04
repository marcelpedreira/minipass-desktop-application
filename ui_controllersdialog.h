/********************************************************************************
** Form generated from reading UI file 'controllersdialog.ui'
**
** Created: Fri May 16 13:52:45 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLERSDIALOG_H
#define UI_CONTROLLERSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_controllersDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *typeEdit;
    QLabel *label;
    QLineEdit *addressEdit;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *nextButton;
    QPushButton *previousButton;
    QPushButton *newButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *quitButton;

    void setupUi(QDialog *controllersDialog)
    {
        if (controllersDialog->objectName().isEmpty())
            controllersDialog->setObjectName(QString::fromUtf8("controllersDialog"));
        controllersDialog->resize(400, 198);
        verticalLayout_2 = new QVBoxLayout(controllersDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(controllersDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        typeEdit = new QLineEdit(controllersDialog);
        typeEdit->setObjectName(QString::fromUtf8("typeEdit"));
        typeEdit->setEnabled(false);

        gridLayout->addWidget(typeEdit, 1, 1, 1, 1);

        label = new QLabel(controllersDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        addressEdit = new QLineEdit(controllersDialog);
        addressEdit->setObjectName(QString::fromUtf8("addressEdit"));
        addressEdit->setEnabled(false);

        gridLayout->addWidget(addressEdit, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        nextButton = new QPushButton(controllersDialog);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        verticalLayout->addWidget(nextButton);

        previousButton = new QPushButton(controllersDialog);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));

        verticalLayout->addWidget(previousButton);

        newButton = new QPushButton(controllersDialog);
        newButton->setObjectName(QString::fromUtf8("newButton"));

        verticalLayout->addWidget(newButton);

        deleteButton = new QPushButton(controllersDialog);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        verticalLayout->addWidget(deleteButton);


        gridLayout_2->addLayout(verticalLayout, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(268, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 0, 1, 2);

        quitButton = new QPushButton(controllersDialog);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        gridLayout_2->addWidget(quitButton, 2, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        retranslateUi(controllersDialog);

        QMetaObject::connectSlotsByName(controllersDialog);
    } // setupUi

    void retranslateUi(QDialog *controllersDialog)
    {
        controllersDialog->setWindowTitle(QApplication::translate("controllersDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("controllersDialog", "Tipo:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("controllersDialog", "Direccion:", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("controllersDialog", "Siguiente", 0, QApplication::UnicodeUTF8));
        previousButton->setText(QApplication::translate("controllersDialog", "Anterior", 0, QApplication::UnicodeUTF8));
        newButton->setText(QApplication::translate("controllersDialog", "Nuevo", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("controllersDialog", "Borrar", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("controllersDialog", "Cerrar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class controllersDialog: public Ui_controllersDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLERSDIALOG_H
