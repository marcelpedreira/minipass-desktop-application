/********************************************************************************
** Form generated from reading UI file 'insdialog.ui'
**
** Created: Mon Apr 28 01:10:36 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSDIALOG_H
#define UI_INSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_insDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *nameEdit;
    QLabel *label_4;
    QLineEdit *controllerEdit;
    QLabel *label_5;
    QLineEdit *positionEdit;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QListWidget *activatedOutListWidget;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *addOutButton;
    QSpacerItem *verticalSpacer;
    QPushButton *deleteOutButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QListWidget *noActivatedOutListWidget;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QPushButton *submitButton;
    QPushButton *revertButton;

    void setupUi(QDialog *insDialog)
    {
        if (insDialog->objectName().isEmpty())
            insDialog->setObjectName(QString::fromUtf8("insDialog"));
        insDialog->resize(446, 509);
        verticalLayout = new QVBoxLayout(insDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_2 = new QGroupBox(insDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        nameEdit = new QLineEdit(groupBox_2);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        controllerEdit = new QLineEdit(groupBox_2);
        controllerEdit->setObjectName(QString::fromUtf8("controllerEdit"));
        controllerEdit->setEnabled(false);

        gridLayout->addWidget(controllerEdit, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        positionEdit = new QLineEdit(groupBox_2);
        positionEdit->setObjectName(QString::fromUtf8("positionEdit"));
        positionEdit->setEnabled(false);

        gridLayout->addWidget(positionEdit, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 1, 0, 1, 1);

        groupBox = new QGroupBox(insDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        activatedOutListWidget = new QListWidget(groupBox);
        activatedOutListWidget->setObjectName(QString::fromUtf8("activatedOutListWidget"));

        verticalLayout_4->addWidget(activatedOutListWidget);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalSpacer_2 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        addOutButton = new QPushButton(groupBox);
        addOutButton->setObjectName(QString::fromUtf8("addOutButton"));

        verticalLayout_2->addWidget(addOutButton);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        deleteOutButton = new QPushButton(groupBox);
        deleteOutButton->setObjectName(QString::fromUtf8("deleteOutButton"));

        verticalLayout_2->addWidget(deleteOutButton);

        verticalSpacer_2 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(14, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        noActivatedOutListWidget = new QListWidget(groupBox);
        noActivatedOutListWidget->setObjectName(QString::fromUtf8("noActivatedOutListWidget"));

        verticalLayout_3->addWidget(noActivatedOutListWidget);


        horizontalLayout_2->addLayout(verticalLayout_3);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 2, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_5, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        previousButton = new QPushButton(insDialog);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));

        horizontalLayout->addWidget(previousButton);

        nextButton = new QPushButton(insDialog);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        horizontalLayout->addWidget(nextButton);

        submitButton = new QPushButton(insDialog);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));

        horizontalLayout->addWidget(submitButton);

        revertButton = new QPushButton(insDialog);
        revertButton->setObjectName(QString::fromUtf8("revertButton"));

        horizontalLayout->addWidget(revertButton);


        gridLayout_4->addLayout(horizontalLayout, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_4);


        retranslateUi(insDialog);

        QMetaObject::connectSlotsByName(insDialog);
    } // setupUi

    void retranslateUi(QDialog *insDialog)
    {
        insDialog->setWindowTitle(QApplication::translate("insDialog", "Entradas", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("insDialog", "Edicion:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("insDialog", "Entrada:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("insDialog", "Controlador:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("insDialog", "Posicion:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("insDialog", "Configuracion:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("insDialog", "Salidas activadas:", 0, QApplication::UnicodeUTF8));
        addOutButton->setText(QApplication::translate("insDialog", "<<", 0, QApplication::UnicodeUTF8));
        deleteOutButton->setText(QApplication::translate("insDialog", ">>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("insDialog", "Salidas no activadas:", 0, QApplication::UnicodeUTF8));
        previousButton->setText(QApplication::translate("insDialog", "Anterior", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("insDialog", "Siguiente", 0, QApplication::UnicodeUTF8));
        submitButton->setText(QApplication::translate("insDialog", "Salvar", 0, QApplication::UnicodeUTF8));
        revertButton->setText(QApplication::translate("insDialog", "Deshacer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class insDialog: public Ui_insDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSDIALOG_H
