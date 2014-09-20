#include "databaseprovider.h"
#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    this->showAllDepartments();
    this->showTooltip();
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_closeButton_clicked()
{
    emit departmentsUpdated();

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
        this->showAllDepartments();
    } else
    {
        QMessageBox::critical(this, "Error", "Something bad happened!", QMessageBox::Ok);
    }

    emit departmentsUpdated();
}

void SettingsWindow::showAllDepartments()
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

void SettingsWindow::showTooltip()
{
    ui->departmentNameEdit->setToolTip(tr("Enter department name and press plus to add one"));
    ui->departmentNameEdit->setFocus();
    // QToolTip::showText(ui->departmentNameEdit->mapToGlobal(QPoint(0, 0)), tr("Enter department name and press plus to add one"));
}
