#ifndef CREATEORDERWINDOW_H
#define CREATEORDERWINDOW_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class CreateOrderWindow;
}

class CreateOrderWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CreateOrderWindow(QWidget *parent = 0);
    ~CreateOrderWindow();

private slots:
    void on_createOrderButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::CreateOrderWindow *ui;
};

#endif // CREATEORDERWINDOW_H
