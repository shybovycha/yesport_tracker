#include "visitordetailswindow.h"
#include "ui_visitordetailswindow.h"

VisitorDetailsWindow::VisitorDetailsWindow(int visitorId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisitorDetailsWindow)
{
    this->visitorId = visitorId;

    ui->setupUi(this);
}

VisitorDetailsWindow::~VisitorDetailsWindow()
{
    delete ui;
}

void VisitorDetailsWindow::on_createOrderButton_clicked()
{
    CreateOrderWindow* window = new CreateOrderWindow();
    window->show();
}

void VisitorDetailsWindow::on_closeButton_clicked()
{
    this->close();
}
