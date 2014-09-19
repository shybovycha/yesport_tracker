#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>

#include "databaseprovider.h"

class MyApplication : public QApplication
{
    Q_OBJECT
public:
    explicit MyApplication(int argc, char **argv);

    void initDatabase();
    bool isAnyDepartmentPresent();

signals:

public slots:

};

#endif // MYAPPLICATION_H