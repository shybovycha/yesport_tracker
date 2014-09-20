#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    this->showAllDepartments();
    this->showAllPrograms();
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
        QMessageBox::warning(this, tr("Error"), tr("Could not create nothing"), QMessageBox::Ok);
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
        QMessageBox::critical(this, tr("Error"), tr("Something bad happened!"), QMessageBox::Ok);
    }

    emit departmentsUpdated();
}

void SettingsWindow::on_removeDepartmentButton_clicked()
{
    if (ui->departmentsList->selectedItems().empty())
    {
        QMessageBox::warning(this, tr("Error"), tr("Could not remove nothing"), QMessageBox::Ok);
        return;
    }

    DatabaseRowListItem *item = ((DatabaseRowListItem*) ui->departmentsList->selectedItems().first());

    int res = QMessageBox::question(this, tr("WARNING"), tr("Do you really want to delete `%1` section?").arg(item->text()), QMessageBox::Yes, QMessageBox::No);

    if (res == QMessageBox::No)
    {
        return;
    }

    QSqlQuery query;

    query.prepare("DELETE FROM departments WHERE id = :department_id");
    query.bindValue(":department_id", item->getId());
    bool success = query.exec();

    if (success)
    {
        QMessageBox::information(this, tr("Notice"), tr("Removed section successfully"), QMessageBox::Ok);
    } else
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not remove section"), QMessageBox::Ok);
    }

    this->showAllDepartments();
}

void SettingsWindow::showAllDepartments()
{
    QSqlQuery query;

    query.prepare("SELECT id, name FROM departments");
    query.exec();

    ui->departmentsList->clear();

    while (query.next())
    {
        ui->departmentsList->addItem(new DatabaseRowListItem(query.value("name").toString(), query.value("id").toInt()));
    }
}

void SettingsWindow::showAllPrograms()
{
    QSqlQuery query;

    query.prepare("SELECT id, name FROM programs");
    query.exec();

    ui->programsList->clear();

    while (query.next())
    {
        ui->programsList->addItem(new DatabaseRowListItem(query.value("name").toString(), query.value("id").toInt()));
    }
}

void SettingsWindow::showTooltip()
{
    ui->departmentNameEdit->setToolTip(tr("Enter department name and press plus to add one"));
    ui->departmentNameEdit->setFocus();
    // QToolTip::showText(ui->departmentNameEdit->mapToGlobal(QPoint(0, 0)), tr("Enter department name and press plus to add one"));
}

void SettingsWindow::on_addProgramButton_clicked()
{

}
