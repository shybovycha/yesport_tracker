#include "databaseprovider.h"

void DatabaseProvider::initDatabase()
{
    QSqlDatabase db;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("yesport_database.sqlite");

    if (!db.open())
    {
        QMessageBox msgBox;

        msgBox.setText(QObject::tr("Failed to open database."));
        msgBox.setIcon(QMessageBox::Critical);

        qDebug() << "Database error:" << db.lastError().text();

        if (msgBox.exec() == QMessageBox::Ok)
        {
            QApplication::quit();
            return;
        }
    }

    QList<QString> queries;

    queries.push_back("CREATE TABLE IF NOT EXISTS departments (id integer primary key autoincrement, name varchar(255))");
    queries.push_back("CREATE TABLE IF NOT EXISTS visitors (id integer primary key autoincrement, department_id integer, name varchar(255))");
    queries.push_back("CREATE TABLE IF NOT EXISTS programs (id integer primary key autoincrement, department_id integer, name varchar(355), cost real, track_visits integer)");
    queries.push_back("CREATE TABLE IF NOT EXISTS orders (id integer primary key autoincrement, program_id integer, visitor_id integer, created_at date, payed_until date, visits_left integer, amount real)");

    QListIterator<QString> it(queries);

    while (it.hasNext())
    {
        QString query = it.next();

        db.exec(query);

        if (db.lastError().type() != QSqlError::NoError)
            qDebug() << db.lastError();
    }
}

bool DatabaseProvider::isAnyDepartmentPresent()
{
    return (countRows("departments") > 0);
}

bool DatabaseProvider::isAnyProgramPresent()
{
    return (countRows("programs") > 0);
}

int DatabaseProvider::countRows(const QString &tableName)
{
    QSqlQuery query;

    query.exec(QString("SELECT COUNT(*) AS count FROM %1").arg(tableName));

    while (query.next())
    {
        return query.value("count").toInt();
    }

    return 0;
}
