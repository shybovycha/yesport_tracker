#ifndef CREATEORDERWINDOW_H
#define CREATEORDERWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class CreateOrderWindow;
}

class CreateOrderWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CreateOrderWindow(int visitorId, QWidget *parent = 0);
    ~CreateOrderWindow();

signals:
    void closed();

private slots:
    void on_createOrderButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::CreateOrderWindow *ui;
    int visitorId;
};

#endif // CREATEORDERWINDOW_H
