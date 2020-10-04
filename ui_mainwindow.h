/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri May 16 13:52:45 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionControladores;
    QAction *actionNiveles_de_acceso;
    QAction *actionUsuarios;
    QAction *actionSobre;
    QAction *actionSystemUpdate;
    QAction *actionPuertas;
    QAction *actionLimpiar_eventos;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuOperaciones;
    QMenu *menuAyuda;
    QMenu *menuOpciones;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(577, 520);
        actionControladores = new QAction(MainWindow);
        actionControladores->setObjectName(QString::fromUtf8("actionControladores"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/resourses/tarjeta_expansion.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionControladores->setIcon(icon);
        actionNiveles_de_acceso = new QAction(MainWindow);
        actionNiveles_de_acceso->setObjectName(QString::fromUtf8("actionNiveles_de_acceso"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/resourses/security_agent.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNiveles_de_acceso->setIcon(icon1);
        actionUsuarios = new QAction(MainWindow);
        actionUsuarios->setObjectName(QString::fromUtf8("actionUsuarios"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/resourses/id_card.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUsuarios->setIcon(icon2);
        actionSobre = new QAction(MainWindow);
        actionSobre->setObjectName(QString::fromUtf8("actionSobre"));
        actionSystemUpdate = new QAction(MainWindow);
        actionSystemUpdate->setObjectName(QString::fromUtf8("actionSystemUpdate"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/resourses/DB Update.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSystemUpdate->setIcon(icon3);
        actionPuertas = new QAction(MainWindow);
        actionPuertas->setObjectName(QString::fromUtf8("actionPuertas"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/resourses/puerta-icono-6807-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPuertas->setIcon(icon4);
        actionLimpiar_eventos = new QAction(MainWindow);
        actionLimpiar_eventos->setObjectName(QString::fromUtf8("actionLimpiar_eventos"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setShowGrid(false);
        tableView->setGridStyle(Qt::SolidLine);
        tableView->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(tableView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 577, 25));
        menuBar->setFocusPolicy(Qt::TabFocus);
        menuBar->setContextMenuPolicy(Qt::ActionsContextMenu);
        menuBar->setAutoFillBackground(true);
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(false);
        menuOperaciones = new QMenu(menuBar);
        menuOperaciones->setObjectName(QString::fromUtf8("menuOperaciones"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
        menuOpciones = new QMenu(menuBar);
        menuOpciones->setObjectName(QString::fromUtf8("menuOpciones"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setAcceptDrops(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuOperaciones->menuAction());
        menuBar->addAction(menuOpciones->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuOperaciones->addAction(actionControladores);
        menuOperaciones->addAction(actionPuertas);
        menuOperaciones->addAction(actionNiveles_de_acceso);
        menuOperaciones->addAction(actionUsuarios);
        menuAyuda->addAction(actionSobre);
        menuOpciones->addAction(actionSystemUpdate);
        menuOpciones->addAction(actionLimpiar_eventos);
        mainToolBar->addAction(actionControladores);
        mainToolBar->addAction(actionPuertas);
        mainToolBar->addAction(actionUsuarios);
        mainToolBar->addAction(actionSystemUpdate);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MiniPass", 0, QApplication::UnicodeUTF8));
        actionControladores->setText(QApplication::translate("MainWindow", "Controladores...", 0, QApplication::UnicodeUTF8));
        actionNiveles_de_acceso->setText(QApplication::translate("MainWindow", "Niveles de acceso...", 0, QApplication::UnicodeUTF8));
        actionUsuarios->setText(QApplication::translate("MainWindow", "Usuarios...", 0, QApplication::UnicodeUTF8));
        actionSobre->setText(QApplication::translate("MainWindow", "Sobre...", 0, QApplication::UnicodeUTF8));
        actionSystemUpdate->setText(QApplication::translate("MainWindow", "Actualizar sistema", 0, QApplication::UnicodeUTF8));
        actionPuertas->setText(QApplication::translate("MainWindow", "Puertas...", 0, QApplication::UnicodeUTF8));
        actionLimpiar_eventos->setText(QApplication::translate("MainWindow", "Limpiar eventos", 0, QApplication::UnicodeUTF8));
        menuOperaciones->setTitle(QApplication::translate("MainWindow", "Configuracion", 0, QApplication::UnicodeUTF8));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", 0, QApplication::UnicodeUTF8));
        menuOpciones->setTitle(QApplication::translate("MainWindow", "Operaciones", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
