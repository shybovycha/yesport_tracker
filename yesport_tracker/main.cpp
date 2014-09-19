#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    MyApplication *app = new MyApplication(argc, argv);

    app->initDatabase();

    MainWindow *w = new MainWindow();
    w->show();

    if (!app->isAnyDepartmentPresent())
    {
        w->showSettingsWindow();
    }

    return app->exec();
}
