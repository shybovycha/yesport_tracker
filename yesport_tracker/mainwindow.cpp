#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->showAllDepartments();
    this->filterVisitors();

    ui->visitorDetailsFrame->setEnabled(false);
    this->showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_settings_window_closed()
{
    this->showAllDepartments();
}

void MainWindow::showAllDepartments()
{
    QSqlQuery query;

    query.prepare("SELECT id, name FROM departments");
    query.exec();

    ui->departmentsList->clear();

    while (query.next())
    {
        ui->departmentsList->addItem(query.value("name").toString(), query.value("id").toInt());
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

    query.prepare("INSERT INTO visitors (name, department_id) VALUES (:name, :department_id)");
    query.bindValue(":name", name);
    query.bindValue(":department_id", ui->departmentsList->itemData(ui->departmentsList->currentIndex()).toInt());
    bool res = query.exec();

    if (res)
    {
        this->filterVisitors();
    } else
    {
        QMessageBox::critical(this, "Error", "Something bad happened!", QMessageBox::Ok);
    }
}

void MainWindow::filterVisitors()
{
    this->filterVisitors(ui->quickSearchEdit->text(), ui->departmentsList->itemData(ui->departmentsList->currentIndex()).toInt());
}

void MainWindow::filterVisitors(const QString &text, int departmentId)
{
    ui->visitorsList->clear();

    QSqlQuery query;

    if (text.isEmpty())
    {
        ui->addVisitorButton->setEnabled(false);
        query.prepare("SELECT id, name FROM visitors WHERE department_id = :department_id");
        query.bindValue(":department_id", departmentId);
    } else
    {
        query.prepare("SELECT id, name FROM visitors WHERE name LIKE :name AND department_id = :department_id COLLATE NOCASE");
        query.bindValue(":name", QString("%%%1%%").arg(text));
        query.bindValue(":department_id", departmentId);
    }

    query.exec();

    while (query.next())
    {
        ui->visitorsList->addItem(new DatabaseRowListItem(query.value("name").toString(), query.value("id").toInt()));
    }

    ui->addVisitorButton->setEnabled(true);
}

void MainWindow::on_quickSearchEdit_textChanged(const QString &text)
{
    this->filterVisitors(text, ui->departmentsList->itemData(ui->departmentsList->currentIndex()).toInt());
}

void MainWindow::on_departmentsList_editTextChanged(const QString &text)
{
    if (text.isEmpty())
    {
        showAllDepartments();
        return;
    }
}

void MainWindow::on_settingsButton_clicked()
{
    showSettingsWindow();
}

void MainWindow::showSettingsWindow()
{
    SettingsWindow* window = new SettingsWindow();

    connect(window, SIGNAL(departmentsUpdated()), this, SLOT(on_settings_window_closed()));

    window->activateDepartmentsTab();
    window->show();
}

void MainWindow::on_visitorsList_itemSelectionChanged()
{
    if (ui->visitorsList->selectedItems().empty())
    {
        ui->visitorDetailsFrame->setEnabled(false);
        return;
    }

    DatabaseRowListItem* item = (DatabaseRowListItem*) ui->visitorsList->selectedItems().first();

    int visitorId = item->getId();

    loadVisitorDetails(visitorId);
}

void MainWindow::loadVisitorDetails(int visitorId)
{
    if (visitorId < 1)
    {
        ui->visitorDetailsFrame->setEnabled(false);
        return;
    }

    QSqlQuery query;

    query.prepare("SELECT id, name FROM visitors WHERE id = :visitorId LIMIT 1");
    query.bindValue(":visitorId", visitorId);
    query.exec();

    QString visitorName;

    while (query.next())
    {
        visitorName = query.value("name").toString();
    }

    if (visitorName.isEmpty())
    {
        ui->visitorDetailsFrame->setEnabled(false);
        return;
    }

    ui->visitorNameEdit->setText(visitorName);

    query.prepare("SELECT A.id AS order_id, A.created_at AS created_at, A.amount AS amount, A.payed_until AS payed_until, A.program_id AS program_id, B.name AS program_name FROM orders AS A JOIN programs as B ON A.program_id = B.id WHERE A.visitor_id = :visitorId");
    query.bindValue(":visitorId", visitorId);
    query.exec();

    ui->visitorOrdersList->clear();

    while (query.next())
    {
        QDate created_at = query.value("created_at").toDate();
        QDate payed_until = query.value("payed_until").toDate();
        QString program_name = query.value("program_name").toString();
        float amount = query.value("amount").toFloat();
        int orderId = query.value("order_id").toInt();

        QString created_at_str = created_at.toString("dd MMM yyyy");
        QString payed_until_str = payed_until.toString("dd MMM yyyy");
        QString orderRow = tr("%1 - %2 UAH for %3 until %4").arg(created_at_str).arg(amount).arg(program_name).arg(payed_until_str);

        ui->visitorOrdersList->addItem(new DatabaseRowListItem(orderRow, orderId));
    }

    ui->visitorDetailsFrame->setEnabled(true);
}

void MainWindow::on_create_order_window_closed()
{
    DatabaseRowListItem* item = (DatabaseRowListItem*) ui->visitorsList->selectedItems().first();

    int visitorId = item->getId();

    loadVisitorDetails(visitorId);
}

void MainWindow::on_createOrderButton_clicked()
{
    DatabaseRowListItem* item = (DatabaseRowListItem*) ui->visitorsList->selectedItems().first();

    int visitorId = item->getId();

    CreateOrderWindow* window = new CreateOrderWindow(visitorId);

    connect(window, SIGNAL(closed()), this, SLOT(on_create_order_window_closed()));

    window->show();

    if (!DatabaseProvider::isAnyProgramPresent())
    {
        SettingsWindow* settings_window = new SettingsWindow();

        connect(settings_window, SIGNAL(programsUpdated()), window, SLOT(on_settings_window_programsUpdated()));

        QMessageBox::information(settings_window, tr("Information"), tr("There are no services in the database. Create a few in this window, please."), QMessageBox::Ok);

        settings_window->activateProgramsTab();
        settings_window->show();
    }
}

void MainWindow::on_visitorNameEdit_textEdited(const QString &arg1)
{
    ui->saveVisitorDetailsButton->setEnabled(true);
}

void MainWindow::on_departmentsList_currentIndexChanged(const QString &arg1)
{
    this->filterVisitors();
}
