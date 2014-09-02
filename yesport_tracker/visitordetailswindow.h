#ifndef VISITORDETAILSWINDOW_H
#define VISITORDETAILSWINDOW_H

#include <QtSql>
#include <QWidget>

namespace Ui {
class VisitorDetailsWindow;
}

class VisitorDetailsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit VisitorDetailsWindow(int visitorId, QWidget *parent = 0);
    ~VisitorDetailsWindow();

private:
    int visitorId;
    Ui::VisitorDetailsWindow *ui;
};

#endif // VISITORDETAILSWINDOW_H
