#include "myapplication.h"

MyApplication::MyApplication(int argc, char **argv) : QApplication(argc, argv)
{
}

void MyApplication::initDatabase()
{
    QSqlDatabase db;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("yesport_database.sqlite");

    if (!db.open())
    {
        QMessageBox msgBox;

        msgBox.setText(tr("Failed to open database."));
        msgBox.setIcon(QMessageBox::Critical);

        if (msgBox.exec() == QMessageBox::Ok)
        {
            QApplication::quit();
        }
    }

    db.exec("CREATE TABLE IF NOT EXISTS departments (id integer primary key autoincrement, name varchar(255))");

    if (db.lastError().type() != QSqlError::NoError)
        qDebug() << db.lastError();

    db.exec("CREATE TABLE IF NOT EXISTS visitors (id integer primary key autoincrement, department_id integer, name varchar(255))");

    if (db.lastError().type() != QSqlError::NoError)
        qDebug() << db.lastError();

    db.exec("CREATE TABLE IF NOT EXISTS programs (id integer primary key autoincrement, department_id integer, name varchar(355), cost real, track_visits integer)");

    if (db.lastError().type() != QSqlError::NoError)
        qDebug() << db.lastError();

    db.exec("CREATE TABLE IF NOT EXISTS orders (id integer primary key autoincrement, program_id integer, visitor_id integer, created_at date, payed_until date, visits_left integer, amount real)");

    if (db.lastError().type() != QSqlError::NoError)
        qDebug() << db.lastError();
}

bool MyApplication::isAnyDepartmentPresent()
{
    QSqlQuery query;

    query.exec("SELECT COUNT(*) FROM departments");

    while (query.next())
    {
        return (query.value(0).toInt() > 0);
    }

    return false;
}
