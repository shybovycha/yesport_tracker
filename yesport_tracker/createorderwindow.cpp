#include "createorderwindow.h"
#include "ui_createorderwindow.h"

CreateOrderWindow::CreateOrderWindow(int visitorId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateOrderWindow),
    visitorId(visitorId)
{
    ui->setupUi(this);
}

CreateOrderWindow::~CreateOrderWindow()
{
    delete ui;
}

void CreateOrderWindow::on_createOrderButton_clicked()
{
    QDateTime today = QDateTime::currentDateTime();
    QDate payedUntil = ui->datePicker->selectedDate();
    float amount = ui->amountEdit->value();

    QSqlQuery query;

    query.prepare("INSERT INTO orders (created_at, amount, visitor_id, payed_until) VALUES (:created_at, :amount, :visitor_id, :payed_until)");
    query.bindValue(":visitor_id", visitorId);
    query.bindValue(":amount", amount);
    query.bindValue(":created_at", today);
    query.bindValue(":payed_until", payedUntil);
    bool success = query.exec();

    qDebug() << "NEW ORDER:";
    qDebug() << QString("%1 - %2 UAH. Until %3").arg(today.toString("dd MMM yyyy")).arg(amount).arg(payedUntil.toString("dd MMM yyyy"));
    qDebug() << ((success) ? "SUCCESS" : "FAILURE");

    emit closed();

    this->close();
}

void CreateOrderWindow::on_cancelButton_clicked()
{
    emit closed();

    this->close();
}
