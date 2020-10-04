/********************************************************************************
** Form generated from reading UI file 'reportwindow.ui'
**
** Created: Thu Jan 23 20:11:44 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTWINDOW_H
#define UI_REPORTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportWindow
{
public:
    QAction *actionImprimir;
    QAction *actionSalir;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QDateTimeEdit *inicialTimeEdit;
    QLabel *label_2;
    QDateTimeEdit *finalTimeEdit;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_4;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QTableWidget *reportsTableWidget;
    QMenuBar *menubar;
    QMenu *menuArchivo;

    void setupUi(QMainWindow *ReportWindow)
    {
        if (ReportWindow->objectName().isEmpty())
            ReportWindow->setObjectName(QString::fromUtf8("ReportWindow"));
        ReportWindow->resize(726, 498);
        actionImprimir = new QAction(ReportWindow);
        actionImprimir->setObjectName(QString::fromUtf8("actionImprimir"));
        actionSalir = new QAction(ReportWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        centralwidget = new QWidget(ReportWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        inicialTimeEdit = new QDateTimeEdit(groupBox);
        inicialTimeEdit->setObjectName(QString::fromUtf8("inicialTimeEdit"));

        gridLayout->addWidget(inicialTimeEdit, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        finalTimeEdit = new QDateTimeEdit(groupBox);
        finalTimeEdit->setObjectName(QString::fromUtf8("finalTimeEdit"));

        gridLayout->addWidget(finalTimeEdit, 3, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout_2->addWidget(checkBox_5, 0, 0, 1, 1);

        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout_2->addWidget(checkBox_3, 1, 0, 1, 1);

        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_2->addWidget(checkBox, 2, 0, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_2->addWidget(checkBox_2, 3, 0, 1, 1);

        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_2->addWidget(checkBox_4, 4, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        reportsTableWidget = new QTableWidget(centralwidget);
        reportsTableWidget->setObjectName(QString::fromUtf8("reportsTableWidget"));
        reportsTableWidget->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout->addWidget(reportsTableWidget);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        ReportWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ReportWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 726, 23));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        ReportWindow->setMenuBar(menubar);

        menubar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionImprimir);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);

        retranslateUi(ReportWindow);

        QMetaObject::connectSlotsByName(ReportWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ReportWindow)
    {
        ReportWindow->setWindowTitle(QApplication::translate("ReportWindow", "Reportes", 0, QApplication::UnicodeUTF8));
        actionImprimir->setText(QApplication::translate("ReportWindow", "Imprimir...", 0, QApplication::UnicodeUTF8));
        actionImprimir->setShortcut(QApplication::translate("ReportWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionSalir->setText(QApplication::translate("ReportWindow", "Salir", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ReportWindow", "Fecha y Hora: ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ReportWindow", "Inicio:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ReportWindow", "Final:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ReportWindow", "Tipos de eventos:", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("ReportWindow", "Acceso concedido", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("ReportWindow", "Acceso denegado", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("ReportWindow", "REX concedido", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("ReportWindow", "Entrada activada", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("ReportWindow", "Entrada desactivada", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ReportWindow", "Generar", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("ReportWindow", "Archivo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ReportWindow: public Ui_ReportWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTWINDOW_H
