#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QToolTip>
#include <QSqlQuery>

#include "databaserowlistitem.h"

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
    void activateProgramsTab();
    void activateDepartmentsTab();

signals:
    void departmentsUpdated();
    void programsUpdated();

private slots:
    void on_closeButton_clicked();
    void on_addDepartmentButton_clicked();
    void on_removeDepartmentButton_clicked();
    void on_addProgramButton_clicked();

    void on_removeProgramButton_clicked();

    void on_departmentsList_itemSelectionChanged();

    void on_departmentNameEdit_textEdited(const QString &arg1);

    void on_programsList_itemSelectionChanged();

    void on_programNameEdit_textEdited(const QString &arg1);

private:
    void showAllDepartments();
    void showAllPrograms();

    Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
