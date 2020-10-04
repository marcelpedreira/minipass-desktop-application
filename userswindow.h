#ifndef USERSWINDOW_H
#define USERSWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QtGui>
#include "ui_userswindow.h"

class usersWindow : public QWidget, Ui::usersWindow
{
    Q_OBJECT
    
public:
    explicit usersWindow(QWidget *parent = 0);
    //~usersWindow();
    
private:
    QSqlRelationalTableModel *model;
    QDataWidgetMapper *mapper;

private slots:
    void updateButtons(int row);
    void submit();
    void addUser();
    void deleteUser();
};

#endif // USERSWINDOW_H
