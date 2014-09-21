#ifndef DATABASEPROVIDER_H
#define DATABASEPROVIDER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

class DatabaseProvider
{
public:
    static bool isAnyDepartmentPresent();
    static bool isAnyProgramPresent();
    static void initDatabase();
    static int countRows(const QString &tableName);
};

#endif // DATABASEPROVIDER_H
