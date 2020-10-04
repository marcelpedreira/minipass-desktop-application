/********************************************************************************
** Form generated from reading UI file 'doorsdialog.ui'
**
** Created: Sun Nov 24 13:52:39 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOORSDIALOG_H
#define UI_DOORSDIALOG_H

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

class Ui_doorsDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLineEdit *controllerEdit;
    QLabel *label_3;
    QLineEdit *positionEdit;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *nextButton;
    QPushButton *previousButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *quitButton;

    void setupUi(QDialog *doorsDialog)
    {
        if (doorsDialog->objectName().isEmpty())
            doorsDialog->setObjectName(QString::fromUtf8("doorsDialog"));
        doorsDialog->resize(400, 198);
        verticalLayout_2 = new QVBoxLayout(doorsDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(doorsDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        nameEdit = new QLineEdit(doorsDialog);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setEnabled(true);

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        label_2 = new QLabel(doorsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        controllerEdit = new QLineEdit(doorsDialog);
        controllerEdit->setObjectName(QString::fromUtf8("controllerEdit"));
        controllerEdit->setEnabled(false);

        gridLayout->addWidget(controllerEdit, 1, 1, 1, 1);

        label_3 = new QLabel(doorsDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        positionEdit = new QLineEdit(doorsDialog);
        positionEdit->setObjectName(QString::fromUtf8("positionEdit"));
        positionEdit->setEnabled(false);

        gridLayout->addWidget(positionEdit, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        submitButton = new QPushButton(doorsDialog);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));

        verticalLayout->addWidget(submitButton);

        revertButton = new QPushButton(doorsDialog);
        revertButton->setObjectName(QString::fromUtf8("revertButton"));

        verticalLayout->addWidget(revertButton);

        nextButton = new QPushButton(doorsDialog);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        verticalLayout->addWidget(nextButton);

        previousButton = new QPushButton(doorsDialog);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));

        verticalLayout->addWidget(previousButton);


        gridLayout_2->addLayout(verticalLayout, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 0, 1, 2);

        quitButton = new QPushButton(doorsDialog);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        gridLayout_2->addWidget(quitButton, 2, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        retranslateUi(doorsDialog);

        QMetaObject::connectSlotsByName(doorsDialog);
    } // setupUi

    void retranslateUi(QDialog *doorsDialog)
    {
        doorsDialog->setWindowTitle(QApplication::translate("doorsDialog", "Puertas", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("doorsDialog", "Nombre:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("doorsDialog", "Controlador:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("doorsDialog", "Posicion:", 0, QApplication::UnicodeUTF8));
        submitButton->setText(QApplication::translate("doorsDialog", "Salvar", 0, QApplication::UnicodeUTF8));
        revertButton->setText(QApplication::translate("doorsDialog", "Deshacer", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("doorsDialog", "Siguiente", 0, QApplication::UnicodeUTF8));
        previousButton->setText(QApplication::translate("doorsDialog", "Anterior", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("doorsDialog", "Cerrar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class doorsDialog: public Ui_doorsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOORSDIALOG_H
