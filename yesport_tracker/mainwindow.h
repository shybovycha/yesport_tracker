#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <QListWidgetItem>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addVisitorButton_clicked();
    void on_quickSearchEdit_textChanged(const QString &arg1);
    void on_departmentsList_editTextChanged(const QString &arg1);
    void on_usersList_itemDoubleClicked(QListWidgetItem *item);

    void on_settingsButton_clicked();

private:
    void initDatabase();
    void showAllVisitors();
    void showAllDepartments();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
