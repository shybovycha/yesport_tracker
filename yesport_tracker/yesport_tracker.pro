#-------------------------------------------------
#
# Project created by QtCreator 2014-09-02T14:25:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = yesport_tracker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    visitorslistitem.cpp \
    createorderwindow.cpp \
    settingswindow.cpp \
    myapplication.cpp \
    departmentslistitem.cpp

HEADERS  += mainwindow.h \
    visitorslistitem.h \
    createorderwindow.h \
    settingswindow.h \
    myapplication.h \
    departmentslistitem.h

FORMS    += mainwindow.ui \
    createorderwindow.ui \
    settingswindow.ui

RESOURCES += \
    general.qrc
