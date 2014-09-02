#include "databaseprovider.h"

QSqlDatabase DatabaseProvider::db(bool keep)
{
    static QSqlDatabase db;
    static bool dbisset = false;

    if (keep)
    {
        if (!dbisset)
        {
            db = QSqlDatabase::addDatabase("QSQLITE");
            dbisset = true;
            db.setDatabaseName("yesport_database.sqlite");

            if (!db.open())
            {
                qDebug() << db.lastError().text();
            }
        }
    } else
    {
        db.close();
    }

    return db;
}

