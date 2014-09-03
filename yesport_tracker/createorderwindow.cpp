#include "createorderwindow.h"
#include "ui_createorderwindow.h"

CreateOrderWindow::CreateOrderWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateOrderWindow)
{
    ui->setupUi(this);
}

CreateOrderWindow::~CreateOrderWindow()
{
    delete ui;
}

void CreateOrderWindow::on_createOrderButton_clicked()
{
    qDebug() << ui->datePicker->selectedDate();
    this->close();
}

void CreateOrderWindow::on_cancelButton_clicked()
{
    this->close();
}
