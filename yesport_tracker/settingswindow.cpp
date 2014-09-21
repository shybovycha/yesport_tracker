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

void SettingsWindow::on_addProgramButton_clicked()
{
    QString name = ui->programNameEdit->text();

    if (name.isEmpty())
    {
        QMessageBox::warning(this, tr("Error"), tr("Could not create nothing"), QMessageBox::Ok);
        return;
    }

    QSqlQuery query;

    query.prepare("INSERT INTO programs (name) VALUES (:name)");
    query.bindValue(":name", name);

    bool res = query.exec();

    if (res)
    {
        this->showAllPrograms();
    } else
    {
        QMessageBox::critical(this, tr("Error"), tr("Something bad happened!"), QMessageBox::Ok);
    }

    emit programsUpdated();
}

void SettingsWindow::on_removeProgramButton_clicked()
{
    if (ui->programsList->selectedItems().empty())
    {
        QMessageBox::warning(this, tr("Error"), tr("Could not remove nothing"), QMessageBox::Ok);
        return;
    }

    DatabaseRowListItem *item = ((DatabaseRowListItem*) ui->programsList->selectedItems().first());

    int res = QMessageBox::question(this, tr("WARNING"), tr("Do you really want to delete `%1` service?").arg(item->text()), QMessageBox::Yes, QMessageBox::No);

    if (res == QMessageBox::No)
    {
        return;
    }

    QSqlQuery query;

    query.prepare("DELETE FROM programs WHERE id = :program_id");
    query.bindValue(":program_id", item->getId());
    bool success = query.exec();

    if (success)
    {
        QMessageBox::information(this, tr("Notice"), tr("Removed service successfully"), QMessageBox::Ok);
    } else
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not remove service"), QMessageBox::Ok);
    }

    this->showAllPrograms();

    emit programsUpdated();
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

void SettingsWindow::on_departmentsList_itemSelectionChanged()
{
    if (ui->departmentsList->selectedItems().size() < 1)
    {
        ui->removeDepartmentButton->setEnabled(false);
    } else
    {
        ui->removeDepartmentButton->setEnabled(true);
    }
}

void SettingsWindow::on_departmentNameEdit_textEdited(const QString &text)
{
    if (text.isEmpty())
    {
        ui->addDepartmentButton->setEnabled(false);
    } else
    {
        ui->addDepartmentButton->setEnabled(true);
    }
}

void SettingsWindow::on_programsList_itemSelectionChanged()
{
    if (ui->programsList->selectedItems().size() < 1)
    {
        ui->removeProgramButton->setEnabled(false);
    } else
    {
        ui->removeProgramButton->setEnabled(true);
    }
}

void SettingsWindow::on_programNameEdit_textEdited(const QString &text)
{
    if (text.isEmpty())
    {
        ui->addProgramButton->setEnabled(false);
    } else
    {
        ui->addProgramButton->setEnabled(true);
    }
}

void SettingsWindow::activateDepartmentsTab()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->departmentsTab));
}

void SettingsWindow::activateProgramsTab()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->programsTab));
}
