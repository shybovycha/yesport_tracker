#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QList>

#include "databaseprovider.h"
#include "settingswindow.h"
#include "databaserowlistitem.h"
#include "createorderwindow.h"

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
    void on_settingsButton_clicked();
    void on_settings_window_closed();
    void on_create_order_window_closed();
    void on_visitorsList_itemSelectionChanged();
    void on_createOrderButton_clicked();
    void on_visitorNameEdit_textEdited(const QString &arg1);

    void on_departmentsList_currentIndexChanged(const QString &arg1);

protected:
    void showAllDepartments();
    void filterVisitors();
    void filterVisitors(const QString &text, int departmentId);
    void loadVisitorDetails(int visitorId);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
