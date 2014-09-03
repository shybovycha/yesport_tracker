#include "visitorslistitem.h"
#include "visitordetailswindow.h"
#include "databaseprovider.h"
#include "settingswindow.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    this->initDatabase();

    ui->setupUi(this);

    this->showAllDepartments();
    this->showAllVisitors();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initDatabase()
{
    QSqlDatabase db = DatabaseProvider::db();

    if (!db.isOpen())
    {
        QMessageBox msgBox;

        msgBox.setText(tr("Failed to open database."));
        msgBox.setIcon(QMessageBox::Critical);

        if (msgBox.exec() == QMessageBox::Ok)
        {
            QApplication::quit();
        }
    }

    // query.exec("CREATE TABLE IF NOT EXISTS programs_departments (program_id integer, department_id integer, primary key(program_id, department_id)");

    db.exec("CREATE TABLE IF NOT EXISTS departments (id integer primary key autoincrement, name varchar(255))");

    if (db.lastError().type() != QSqlError::NoError)
        qDebug() << db.lastError();

    db.exec("CREATE TABLE IF NOT EXISTS visitors (id integer primary key autoincrement, name varchar(255))");

    if (db.lastError().type() != QSqlError::NoError)
        qDebug() << db.lastError();

    db.exec("CREATE TABLE IF NOT EXISTS programs (id integer primary key autoincrement, department_id integer, name varchar(355), cost real, track_visits integer)");

    if (db.lastError().type() != QSqlError::NoError)
        qDebug() << db.lastError();

    db.exec("CREATE TABLE IF NOT EXISTS orders (id integer primary key autoincrement, program_id integer, visitor_id integer, created_at date, payed_until date, visits_left integer)");

    if (db.lastError().type() != QSqlError::NoError)
        qDebug() << db.lastError();
}

void MainWindow::showAllVisitors()
{
    QSqlQuery query;

    query.prepare("SELECT id, name FROM visitors");
    query.exec();

    while (query.next())
    {
        ui->usersList->addItem(new VisitorsListItem(query.value(1).toString(), query.value(0).toInt()));
    }
}

void MainWindow::showAllDepartments()
{
    QSqlQuery query;

    query.prepare("SELECT id, name FROM departments");
    query.exec();

    while (query.next())
    {
        ui->departmentsList->addItem(query.value(1).toString());
    }
}

void MainWindow::on_addVisitorButton_clicked()
{
    QString name = ui->quickSearchEdit->text();

    if (name.isEmpty())
    {
        return;
    }

    QSqlQuery query;

    query.prepare("INSERT INTO visitors (name) VALUES (:name)");
    query.bindValue(":name", name);

    bool res = query.exec();

    if (res)
    {
        ui->usersList->addItem(name);
    } else
    {
        qDebug() << DatabaseProvider::db().lastError().text();

        QMessageBox::critical(this, "Error", "Something bad happened!", QMessageBox::Ok);
    }
}

void MainWindow::on_quickSearchEdit_textChanged(const QString &text)
{
    ui->usersList->clear();

    if (text.isEmpty())
    {
        ui->addVisitorButton->setEnabled(false);
        showAllVisitors();
        return;
    }

    QSqlQuery query;

    query.prepare("SELECT id, name FROM visitors WHERE name LIKE :name");
    query.bindValue(":name", QString("%%%1%%").arg(text));
    query.exec();

    while (query.next())
    {
        ui->usersList->addItem(new VisitorsListItem(query.value(1).toString(), query.value(0).toInt()));
    }

    ui->addVisitorButton->setEnabled(true);
}

void MainWindow::on_departmentsList_editTextChanged(const QString &text)
{
    if (text.isEmpty())
    {
        showAllDepartments();
        return;
    }
}

void MainWindow::on_usersList_itemDoubleClicked(QListWidgetItem *item)
{
    int visitorId = ((VisitorsListItem*) item)->getId();

    VisitorDetailsWindow *detailsWindow = new VisitorDetailsWindow(visitorId);
    detailsWindow->show();
}

void MainWindow::on_settingsButton_clicked()
{
    SettingsWindow* window = new SettingsWindow();
    window->show();
}
