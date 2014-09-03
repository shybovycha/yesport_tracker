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
    visitordetailswindow.cpp \
    databaseprovider.cpp \
    createorderwindow.cpp \
    settingswindow.cpp

HEADERS  += mainwindow.h \
    visitorslistitem.h \
    visitordetailswindow.h \
    databaseprovider.h \
    createorderwindow.h \
    settingswindow.h

FORMS    += mainwindow.ui \
    visitordetailswindow.ui \
    createorderwindow.ui \
    settingswindow.ui

RESOURCES += \
    general.qrc
