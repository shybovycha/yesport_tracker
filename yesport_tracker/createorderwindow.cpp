#include "createorderwindow.h"
#include "ui_createorderwindow.h"

CreateOrderWindow::CreateOrderWindow(int visitorId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateOrderWindow),
    visitorId(visitorId)
{
    ui->setupUi(this);

    ui->datePicker->setLocale(QLocale("uk_UA"));

    this->showAllPrograms();
}

CreateOrderWindow::~CreateOrderWindow()
{
    delete ui;
}

void CreateOrderWindow::on_createOrderButton_clicked()
{
    if (ui->programsList->currentIndex() < 0)
    {
        QMessageBox::critical(this, tr("Error"), tr("Select a service first"), QMessageBox::Ok);
        return;
    }

    QDateTime today = QDateTime::currentDateTime();
    QDate payedUntil = ui->datePicker->selectedDate();
    float amount = ui->amountEdit->value();
    int programId = ui->programsList->currentData().toInt();

    QSqlQuery query;

    query.prepare("SELECT name FROM programs WHERE id = :program_id");
    query.bindValue(":program_id", programId);
    query.exec();

    QString programName;

    while (query.next())
    {
        programName = query.value("name").toString();
    }

    query.prepare("INSERT INTO orders (created_at, amount, visitor_id, payed_until, program_id) VALUES (:created_at, :amount, :visitor_id, :payed_until, :program_id)");
    query.bindValue(":visitor_id", visitorId);
    query.bindValue(":amount", amount);
    query.bindValue(":created_at", today);
    query.bindValue(":payed_until", payedUntil);
    query.bindValue(":program_id", programId);
    bool success = query.exec();

    qDebug() << "NEW ORDER:";
    qDebug() << QString("%1 - %2 UAH FOR %3. Until %4").arg(today.toString("dd MMM yyyy")).arg(QString::number(amount, 'f', 2)).arg(programName).arg(payedUntil.toString("dd MMM yyyy"));
    qDebug() << ((success) ? "SUCCESS" : "FAILURE");

    emit closed();

    this->close();
}

void CreateOrderWindow::on_cancelButton_clicked()
{
    emit closed();

    this->close();
}

void CreateOrderWindow::showAllPrograms()
{
    QSqlQuery query;

    query.exec("SELECT id, name FROM programs");

    ui->programsList->clear();

    while (query.next())
    {
        int id = query.value("id").toInt();
        QString name = query.value("name").toString();

        ui->programsList->addItem(name, id);
    }
}

void CreateOrderWindow::on_settings_window_programsUpdated()
{
    this->showAllPrograms();
}
