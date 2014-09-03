#include "databaseprovider.h"
#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_closeButton_clicked()
{
    this->close();
}

void SettingsWindow::on_addDepartmentButton_clicked()
{
    QString name = ui->departmentNameEdit->text();

    if (name.isEmpty())
    {
        return;
    }

    QSqlQuery query;

    query.prepare("INSERT INTO departments (name) VALUES (:name)");
    query.bindValue(":name", name);

    bool res = query.exec();

    if (res)
    {
        ui->departmentsList->addItem(name);
    } else
    {
        qDebug() << DatabaseProvider::db().lastError().text();

        QMessageBox::critical(this, "Error", "Something bad happened!", QMessageBox::Ok);
    }
}
