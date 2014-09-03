#ifndef VISITORDETAILSWINDOW_H
#define VISITORDETAILSWINDOW_H

#include <QtSql>
#include <QWidget>

#include "createorderwindow.h"

namespace Ui {
class VisitorDetailsWindow;
}

class VisitorDetailsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit VisitorDetailsWindow(int visitorId, QWidget *parent = 0);
    ~VisitorDetailsWindow();

private slots:
    void on_createOrderButton_clicked();
    void on_closeButton_clicked();

private:
    int visitorId;
    Ui::VisitorDetailsWindow *ui;
};

#endif // VISITORDETAILSWINDOW_H
