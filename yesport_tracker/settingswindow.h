#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();

private slots:
    void on_closeButton_clicked();

    void on_addDepartmentButton_clicked();

private:
    Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
