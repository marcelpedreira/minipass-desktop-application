/********************************************************************************
** Form generated from reading UI file 'accesslevelwindow.ui'
**
** Created: Mon Apr 28 01:10:36 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCESSLEVELWINDOW_H
#define UI_ACCESSLEVELWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_accessLevelWindow
{
public:
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *newButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QListWidget *accessDoorListWidget;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *addDoorButton;
    QSpacerItem *verticalSpacer;
    QPushButton *deleteDoorButton;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListWidget *doorListWidget;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QPushButton *revertButton;
    QPushButton *submitButton;

    void setupUi(QWidget *accessLevelWindow)
    {
        if (accessLevelWindow->objectName().isEmpty())
            accessLevelWindow->setObjectName(QString::fromUtf8("accessLevelWindow"));
        accessLevelWindow->resize(562, 459);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(accessLevelWindow->sizePolicy().hasHeightForWidth());
        accessLevelWindow->setSizePolicy(sizePolicy);
        accessLevelWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        verticalLayout_6 = new QVBoxLayout(accessLevelWindow);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(accessLevelWindow);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        nameEdit = new QLineEdit(groupBox_2);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        horizontalLayout->addWidget(nameEdit);


        verticalLayout_5->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);


        horizontalLayout_3->addLayout(verticalLayout_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        newButton = new QPushButton(groupBox_2);
        newButton->setObjectName(QString::fromUtf8("newButton"));

        verticalLayout_4->addWidget(newButton);

        deleteButton = new QPushButton(groupBox_2);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        verticalLayout_4->addWidget(deleteButton);


        horizontalLayout_3->addLayout(verticalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 1, 0, 1, 1);

        groupBox = new QGroupBox(accessLevelWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        accessDoorListWidget = new QListWidget(groupBox);
        accessDoorListWidget->setObjectName(QString::fromUtf8("accessDoorListWidget"));

        verticalLayout->addWidget(accessDoorListWidget);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(7);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        addDoorButton = new QPushButton(groupBox);
        addDoorButton->setObjectName(QString::fromUtf8("addDoorButton"));

        verticalLayout_3->addWidget(addDoorButton);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        deleteDoorButton = new QPushButton(groupBox);
        deleteDoorButton->setObjectName(QString::fromUtf8("deleteDoorButton"));

        verticalLayout_3->addWidget(deleteDoorButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        doorListWidget = new QListWidget(groupBox);
        doorListWidget->setObjectName(QString::fromUtf8("doorListWidget"));

        verticalLayout_2->addWidget(doorListWidget);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 2, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        previousButton = new QPushButton(accessLevelWindow);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));

        horizontalLayout_4->addWidget(previousButton);

        nextButton = new QPushButton(accessLevelWindow);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        horizontalLayout_4->addWidget(nextButton);

        revertButton = new QPushButton(accessLevelWindow);
        revertButton->setObjectName(QString::fromUtf8("revertButton"));

        horizontalLayout_4->addWidget(revertButton);

        submitButton = new QPushButton(accessLevelWindow);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));

        horizontalLayout_4->addWidget(submitButton);


        gridLayout_3->addLayout(horizontalLayout_4, 4, 0, 1, 1);


        verticalLayout_6->addLayout(gridLayout_3);


        retranslateUi(accessLevelWindow);

        QMetaObject::connectSlotsByName(accessLevelWindow);
    } // setupUi

    void retranslateUi(QWidget *accessLevelWindow)
    {
        accessLevelWindow->setWindowTitle(QApplication::translate("accessLevelWindow", "Niveles de acceso", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("accessLevelWindow", "Edicion:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("accessLevelWindow", "Nivel de acceso", 0, QApplication::UnicodeUTF8));
        newButton->setText(QApplication::translate("accessLevelWindow", "Nuevo", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("accessLevelWindow", "Borrar", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("accessLevelWindow", "Configuracion:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("accessLevelWindow", "Puertas permitidas", 0, QApplication::UnicodeUTF8));
        addDoorButton->setText(QApplication::translate("accessLevelWindow", "<<", 0, QApplication::UnicodeUTF8));
        deleteDoorButton->setText(QApplication::translate("accessLevelWindow", ">>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("accessLevelWindow", "Puertas no permitidas", 0, QApplication::UnicodeUTF8));
        previousButton->setText(QApplication::translate("accessLevelWindow", "Anterior", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("accessLevelWindow", "Siguiente", 0, QApplication::UnicodeUTF8));
        revertButton->setText(QApplication::translate("accessLevelWindow", "Deshacer", 0, QApplication::UnicodeUTF8));
        submitButton->setText(QApplication::translate("accessLevelWindow", "Salvar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class accessLevelWindow: public Ui_accessLevelWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCESSLEVELWINDOW_H
