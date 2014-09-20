#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QToolTip>
#include <QSqlQuery>

#include "departmentslistitem.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0);

    ~SettingsWindow();

    void showTooltip();

signals:
    void departmentsUpdated();

private slots:
    void on_closeButton_clicked();

    void on_addDepartmentButton_clicked();

    void on_removeDepartmentButton_clicked();

private:
    void showAllDepartments();

    Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
