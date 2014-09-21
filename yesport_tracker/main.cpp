#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>

void myMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString txt;

    switch (type)
    {
        case QtDebugMsg:
            txt = QString("Debug: %1").arg(msg);
        break;

        case QtWarningMsg:
            txt = QString("Warning: %1").arg(msg);
        break;

        case QtCriticalMsg:
            txt = QString("Critical: %1").arg(msg);
        break;

        case QtFatalMsg:
            txt = QString("Fatal: %1").arg(msg);
            abort();
    }

    QFile outFile("yesport_tracker.log");

    outFile.open(QIODevice::WriteOnly | QIODevice::Append);

    QTextStream ts(&outFile);

    ts << txt << endl;
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageHandler);

    QApplication *app = new QApplication(argc, argv);

    QTranslator qtTranslator;
    // add russian locale
    // qtTranslator.load(QLocale::system().name());
    qtTranslator.load("uk_UA");
    app->installTranslator(&qtTranslator);

    DatabaseProvider::initDatabase();

    MainWindow *window = new MainWindow();
    window->show();

    if (!DatabaseProvider::isAnyDepartmentPresent())
    {
        QMessageBox::information(window, QObject::tr("Information"), QObject::tr("There are no sections in the database. Create a few in this window, please. Here, as well, you may create services to set them for payments later."), QMessageBox::Ok);
        window->showSettingsWindow();
    }

    return app->exec();
}
