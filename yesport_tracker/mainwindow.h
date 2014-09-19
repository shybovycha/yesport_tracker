#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <QListWidgetItem>

#include "myapplication.h"
#include "settingswindow.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void showSettingsWindow();
    ~MainWindow();

private slots:
    void on_addVisitorButton_clicked();
    void on_quickSearchEdit_textChanged(const QString &arg1);
    void on_departmentsList_editTextChanged(const QString &arg1);
    void on_usersList_itemDoubleClicked(QListWidgetItem *item);

    void on_settingsButton_clicked();

    void on_settings_window_closed();

protected:
    void showAllVisitors();
    void showAllDepartments();
    void filterVisitors();
    void filterVisitors(const QString &text);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
