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
