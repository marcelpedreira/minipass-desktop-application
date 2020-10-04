#-------------------------------------------------
#
# Project created by QtCreator 2013-12-01T22:17:58
#
#-------------------------------------------------

QT       += core gui\
           sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MiniPass
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    userswindow.cpp \
    tinoutcontroller.cpp \
    tdoorcontroller.cpp \
    tdatamanager.cpp \
    tcontrollermanager.cpp \
    tcontroller.cpp \
    reportwindow.cpp \
    outsdialog.cpp \
    newcontrollerdialog.cpp \
    insdialog.cpp \
    doorsdialog.cpp \
    controllersdialog.cpp \
    accesslevelwindow.cpp

HEADERS  += mainwindow.h \
    wiegand.h \
    userswindow.h \
    tinoutcontroller.h \
    tdoorcontroller.h \
    tdatamanager.h \
    tcontrollermanager.h \
    tcontroller.h \
    reportwindow.h \
    outsdialog.h \
    newcontrollerdialog.h \
    insdialog.h \
    EIncomplette.h \
    doorsdialog.h \
    controllersdialog.h \
    accesslevelwindow.h

FORMS    += mainwindow.ui \
    userswindow.ui \
    reportwindow.ui \
    newcontrollerdialog.ui \
    insdialog.ui \
    doorsdialog.ui \
    accesslevelwindow.ui

OTHER_FILES +=

RESOURCES += \
    MiniPass.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libmodbus-3.0.5/src/.libs/release/ -lmodbus
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libmodbus-3.0.5/src/.libs/debug/ -lmodbus
else:unix: LIBS += -L$$PWD/libmodbus-3.0.5/src/.libs/ -lmodbus

INCLUDEPATH += $$PWD/libmodbus-3.0.5/src/.libs
DEPENDPATH += $$PWD/libmodbus-3.0.5/src/.libs
