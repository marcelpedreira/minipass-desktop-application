/********************************************************************************
** Form generated from reading UI file 'userswindow.ui'
**
** Created: Mon Apr 28 01:10:36 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSWINDOW_H
#define UI_USERSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usersWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *searchButton;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *IDEdit;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLineEdit *lastNameEdit;
    QLabel *label_3;
    QLineEdit *facCodeEdit;
    QLabel *label_4;
    QLineEdit *userCodeEdit;
    QLabel *label_5;
    QComboBox *accessLevelComboBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *newButton;
    QPushButton *deleteButton;
    QPushButton *revertButton;
    QPushButton *submitButton;

    void setupUi(QWidget *usersWindow)
    {
        if (usersWindow->objectName().isEmpty())
            usersWindow->setObjectName(QString::fromUtf8("usersWindow"));
        usersWindow->resize(404, 340);
        verticalLayout_2 = new QVBoxLayout(usersWindow);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_3, 1, 0, 1, 1);

        groupBox = new QGroupBox(usersWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        searchButton = new QPushButton(groupBox);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        verticalLayout->addWidget(searchButton);

        previousButton = new QPushButton(groupBox);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));

        verticalLayout->addWidget(previousButton);

        nextButton = new QPushButton(groupBox);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        verticalLayout->addWidget(nextButton);


        gridLayout_2->addLayout(verticalLayout, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 92, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        IDEdit = new QLineEdit(groupBox);
        IDEdit->setObjectName(QString::fromUtf8("IDEdit"));

        gridLayout->addWidget(IDEdit, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        nameEdit = new QLineEdit(groupBox);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lastNameEdit = new QLineEdit(groupBox);
        lastNameEdit->setObjectName(QString::fromUtf8("lastNameEdit"));

        gridLayout->addWidget(lastNameEdit, 2, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        facCodeEdit = new QLineEdit(groupBox);
        facCodeEdit->setObjectName(QString::fromUtf8("facCodeEdit"));

        gridLayout->addWidget(facCodeEdit, 3, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        userCodeEdit = new QLineEdit(groupBox);
        userCodeEdit->setObjectName(QString::fromUtf8("userCodeEdit"));

        gridLayout->addWidget(userCodeEdit, 4, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        accessLevelComboBox = new QComboBox(groupBox);
        accessLevelComboBox->setObjectName(QString::fromUtf8("accessLevelComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(accessLevelComboBox->sizePolicy().hasHeightForWidth());
        accessLevelComboBox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(accessLevelComboBox, 5, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 3, 1);

        horizontalSpacer_2 = new QSpacerItem(19, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newButton = new QPushButton(usersWindow);
        newButton->setObjectName(QString::fromUtf8("newButton"));

        horizontalLayout->addWidget(newButton);

        deleteButton = new QPushButton(usersWindow);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        revertButton = new QPushButton(usersWindow);
        revertButton->setObjectName(QString::fromUtf8("revertButton"));

        horizontalLayout->addWidget(revertButton);

        submitButton = new QPushButton(usersWindow);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));

        horizontalLayout->addWidget(submitButton);


        gridLayout_3->addLayout(horizontalLayout, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);


        retranslateUi(usersWindow);

        QMetaObject::connectSlotsByName(usersWindow);
    } // setupUi

    void retranslateUi(QWidget *usersWindow)
    {
        usersWindow->setWindowTitle(QApplication::translate("usersWindow", "Usuarios", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("usersWindow", "Identificacion del usuario:", 0, QApplication::UnicodeUTF8));
        searchButton->setText(QApplication::translate("usersWindow", "Buscar", 0, QApplication::UnicodeUTF8));
        previousButton->setText(QApplication::translate("usersWindow", "Anterior", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("usersWindow", "Siguiente", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("usersWindow", "ID:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("usersWindow", "Nombre:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("usersWindow", "Apellido:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("usersWindow", "Codigo de edificio:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("usersWindow", "Codigo de usuario:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("usersWindow", "Nivel de Acceso:", 0, QApplication::UnicodeUTF8));
        newButton->setText(QApplication::translate("usersWindow", "Nuevo", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("usersWindow", "Borrar", 0, QApplication::UnicodeUTF8));
        revertButton->setText(QApplication::translate("usersWindow", "Deshacer", 0, QApplication::UnicodeUTF8));
        submitButton->setText(QApplication::translate("usersWindow", "Salvar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class usersWindow: public Ui_usersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSWINDOW_H
