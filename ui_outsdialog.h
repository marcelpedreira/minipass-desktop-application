/********************************************************************************
** Form generated from reading UI file 'outsdialog.ui'
**
** Created: Sun Nov 24 13:52:39 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTSDIALOG_H
#define UI_OUTSDIALOG_H

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

class Ui_outsDialog
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
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPushButton *quitButton;

    void setupUi(QDialog *outsDialog)
    {
        if (outsDialog->objectName().isEmpty())
            outsDialog->setObjectName(QString::fromUtf8("outsDialog"));
        outsDialog->resize(379, 198);
        verticalLayout_2 = new QVBoxLayout(outsDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(outsDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        nameEdit = new QLineEdit(outsDialog);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        label_2 = new QLabel(outsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        controllerEdit = new QLineEdit(outsDialog);
        controllerEdit->setObjectName(QString::fromUtf8("controllerEdit"));
        controllerEdit->setEnabled(false);

        gridLayout->addWidget(controllerEdit, 1, 1, 1, 1);

        label_3 = new QLabel(outsDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        positionEdit = new QLineEdit(outsDialog);
        positionEdit->setObjectName(QString::fromUtf8("positionEdit"));
        positionEdit->setEnabled(false);

        gridLayout->addWidget(positionEdit, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        submitButton = new QPushButton(outsDialog);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));

        verticalLayout->addWidget(submitButton);

        revertButton = new QPushButton(outsDialog);
        revertButton->setObjectName(QString::fromUtf8("revertButton"));

        verticalLayout->addWidget(revertButton);

        nextButton = new QPushButton(outsDialog);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        verticalLayout->addWidget(nextButton);

        previousButton = new QPushButton(outsDialog);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));

        verticalLayout->addWidget(previousButton);


        gridLayout_2->addLayout(verticalLayout, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 2, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 3, 1, 1);

        quitButton = new QPushButton(outsDialog);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        gridLayout_2->addWidget(quitButton, 2, 2, 1, 2);


        verticalLayout_2->addLayout(gridLayout_2);


        retranslateUi(outsDialog);

        QMetaObject::connectSlotsByName(outsDialog);
    } // setupUi

    void retranslateUi(QDialog *outsDialog)
    {
        outsDialog->setWindowTitle(QApplication::translate("outsDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("outsDialog", "Salida:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("outsDialog", "Controlador:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("outsDialog", "Posicion:", 0, QApplication::UnicodeUTF8));
        submitButton->setText(QApplication::translate("outsDialog", "Salvar", 0, QApplication::UnicodeUTF8));
        revertButton->setText(QApplication::translate("outsDialog", "Deshacer", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("outsDialog", "Siguiente", 0, QApplication::UnicodeUTF8));
        previousButton->setText(QApplication::translate("outsDialog", "Anterior", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("outsDialog", "Cerrar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class outsDialog: public Ui_outsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTSDIALOG_H
