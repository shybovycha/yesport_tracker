#include "visitorslistitem.h"
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

    ui->visitorsList->clear();

    while (query.next())
    {
        ui->visitorsList->addItem(new VisitorsListItem(query.value(1).toString(), query.value(0).toInt()));
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
        QMessageBox::critical(this, "Error", "Something bad happened!", QMessageBox::Ok);
    }
}

void MainWindow::filterVisitors()
{
    this->filterVisitors(ui->quickSearchEdit->text());
}

void MainWindow::filterVisitors(const QString &text)
{
    ui->visitorsList->clear();

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
        ui->visitorsList->addItem(new VisitorsListItem(query.value(1).toString(), query.value(0).toInt()));
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

void MainWindow::on_visitorsList_itemSelectionChanged()
{
    if (ui->visitorsList->selectedItems().empty())
    {
        ui->visitorDetailsFrame->setEnabled(false);
        return;
    }

    VisitorsListItem* item = (VisitorsListItem*) ui->visitorsList->selectedItems().first();

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

    query.prepare("SELECT created_at, amount, payed_until FROM orders WHERE visitor_id = :visitorId");
    query.bindValue(":visitorId", visitorId);
    query.exec();

    ui->visitorOrdersList->clear();

    while (query.next())
    {
        QDate created_at = query.value("created_at").toDate();
        QDate payed_until = query.value("payed_until").toDate();

        float amount = query.value("amount").toFloat();
        QString created_at_str = created_at.toString("dd MMM yyyy");
        QString payed_until_str = payed_until.toString("dd MMM yyyy");

        ui->visitorOrdersList->addItem(tr("%1 - %2 UAH until %3").arg(created_at_str).arg(amount).arg(payed_until_str));
    }

    ui->visitorDetailsFrame->setEnabled(true);
}

void MainWindow::on_create_order_window_closed()
{
    VisitorsListItem* item = (VisitorsListItem*) ui->visitorsList->selectedItems().first();

    int visitorId = item->getId();

    loadVisitorDetails(visitorId);
}

void MainWindow::on_createOrderButton_clicked()
{
    VisitorsListItem* item = (VisitorsListItem*) ui->visitorsList->selectedItems().first();

    int visitorId = item->getId();

    CreateOrderWindow* window = new CreateOrderWindow(visitorId);

    connect(window, SIGNAL(closed()), this, SLOT(on_create_order_window_closed()));

    window->show();
}

void MainWindow::on_visitorNameEdit_textEdited(const QString &arg1)
{
    ui->saveVisitorDetailsButton->setEnabled(true);
}
