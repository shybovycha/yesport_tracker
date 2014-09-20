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
    ui->setupUi(this);

    this->showAllDepartments();
    this->showAllVisitors();

    ui->visitorDetailsFrame->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_settings_window_closed()
{
    this->showAllDepartments();
}

void MainWindow::showAllVisitors()
{
    QSqlQuery query;

    query.prepare("SELECT id, name FROM visitors");
    query.exec();

    ui->usersList->clear();

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

    ui->departmentsList->clear();

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
        this->filterVisitors();
    } else
    {
        qDebug() << DatabaseProvider::db().lastError().text();

        QMessageBox::critical(this, "Error", "Something bad happened!", QMessageBox::Ok);
    }
}

void MainWindow::filterVisitors()
{
    this->filterVisitors(ui->quickSearchEdit->text());
}

void MainWindow::filterVisitors(const QString &text)
{
    ui->usersList->clear();

    if (text.isEmpty())
    {
        ui->addVisitorButton->setEnabled(false);
        this->showAllVisitors();
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

void MainWindow::on_quickSearchEdit_textChanged(const QString &text)
{
    this->filterVisitors(text);
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
    // int visitorId = ((VisitorsListItem*) item)->getId();

    ui->visitorDetailsFrame->setEnabled(true);

    // VisitorDetailsWindow *detailsWindow = new VisitorDetailsWindow(visitorId);
    // detailsWindow->show();
}

void MainWindow::on_settingsButton_clicked()
{
    showSettingsWindow();
}

void MainWindow::showSettingsWindow()
{
    SettingsWindow* window = new SettingsWindow();

    connect(window, SIGNAL(departmentsUpdated()), this, SLOT(on_settings_window_closed()));

    window->show();
}
