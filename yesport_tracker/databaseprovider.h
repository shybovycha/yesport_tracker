#ifndef DATABASEPROVIDER_H
#define DATABASEPROVIDER_H

#include <QtSql>
#include <QDebug>

class DatabaseProvider
{
public:
    static QSqlDatabase db(bool keep = true);
};

#endif // DATABASEPROVIDER_H
