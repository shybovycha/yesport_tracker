/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QFrame *visitorListFrame;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *visitorsLayout;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *departmentsList;
    QToolButton *settingsButton;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout;
    QLineEdit *quickSearchEdit;
    QPushButton *addVisitorButton;
    QListWidget *visitorsList;
    QFrame *visitorDetailsFrame;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *visitorDetailsLayout;
    QLabel *label_9;
    QLineEdit *visitorNameEdit;
    QHBoxLayout *horizontalLayout1;
    QLabel *label_10;
    QPushButton *createOrderButton;
    QListWidget *visitorOrdersList;
    QPushButton *saveVisitorDetailsButton;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(707, 353);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/images/yesport_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(MainWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        visitorListFrame = new QFrame(MainWindow);
        visitorListFrame->setObjectName(QStringLiteral("visitorListFrame"));
        visitorListFrame->setFrameShape(QFrame::StyledPanel);
        visitorListFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_11 = new QHBoxLayout(visitorListFrame);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        visitorsLayout = new QVBoxLayout();
        visitorsLayout->setSpacing(6);
        visitorsLayout->setObjectName(QStringLiteral("visitorsLayout"));
        label_11 = new QLabel(visitorListFrame);
        label_11->setObjectName(QStringLiteral("label_11"));

        visitorsLayout->addWidget(label_11);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        departmentsList = new QComboBox(visitorListFrame);
        departmentsList->setObjectName(QStringLiteral("departmentsList"));
        departmentsList->setEditable(false);

        horizontalLayout_8->addWidget(departmentsList);

        settingsButton = new QToolButton(visitorListFrame);
        settingsButton->setObjectName(QStringLiteral("settingsButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/images/Gear Alt.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingsButton->setIcon(icon1);
        settingsButton->setIconSize(QSize(24, 24));

        horizontalLayout_8->addWidget(settingsButton);


        visitorsLayout->addLayout(horizontalLayout_8);

        label_12 = new QLabel(visitorListFrame);
        label_12->setObjectName(QStringLiteral("label_12"));

        visitorsLayout->addWidget(label_12);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        quickSearchEdit = new QLineEdit(visitorListFrame);
        quickSearchEdit->setObjectName(QStringLiteral("quickSearchEdit"));
        quickSearchEdit->setAcceptDrops(false);
        quickSearchEdit->setClearButtonEnabled(true);

        horizontalLayout->addWidget(quickSearchEdit);

        addVisitorButton = new QPushButton(visitorListFrame);
        addVisitorButton->setObjectName(QStringLiteral("addVisitorButton"));
        addVisitorButton->setEnabled(false);

        horizontalLayout->addWidget(addVisitorButton);


        visitorsLayout->addLayout(horizontalLayout);

        visitorsList = new QListWidget(visitorListFrame);
        visitorsList->setObjectName(QStringLiteral("visitorsList"));
        visitorsList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        visitorsLayout->addWidget(visitorsList);


        horizontalLayout_11->addLayout(visitorsLayout);


        horizontalLayout_3->addWidget(visitorListFrame);

        visitorDetailsFrame = new QFrame(MainWindow);
        visitorDetailsFrame->setObjectName(QStringLiteral("visitorDetailsFrame"));
        visitorDetailsFrame->setFrameShape(QFrame::StyledPanel);
        visitorDetailsFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(visitorDetailsFrame);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        visitorDetailsLayout = new QVBoxLayout();
        visitorDetailsLayout->setSpacing(6);
        visitorDetailsLayout->setObjectName(QStringLiteral("visitorDetailsLayout"));
        label_9 = new QLabel(visitorDetailsFrame);
        label_9->setObjectName(QStringLiteral("label_9"));

        visitorDetailsLayout->addWidget(label_9);

        visitorNameEdit = new QLineEdit(visitorDetailsFrame);
        visitorNameEdit->setObjectName(QStringLiteral("visitorNameEdit"));

        visitorDetailsLayout->addWidget(visitorNameEdit);

        horizontalLayout1 = new QHBoxLayout();
        horizontalLayout1->setSpacing(6);
        horizontalLayout1->setObjectName(QStringLiteral("horizontalLayout1"));
        label_10 = new QLabel(visitorDetailsFrame);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout1->addWidget(label_10);

        createOrderButton = new QPushButton(visitorDetailsFrame);
        createOrderButton->setObjectName(QStringLiteral("createOrderButton"));

        horizontalLayout1->addWidget(createOrderButton);


        visitorDetailsLayout->addLayout(horizontalLayout1);

        visitorOrdersList = new QListWidget(visitorDetailsFrame);
        visitorOrdersList->setObjectName(QStringLiteral("visitorOrdersList"));

        visitorDetailsLayout->addWidget(visitorOrdersList);

        saveVisitorDetailsButton = new QPushButton(visitorDetailsFrame);
        saveVisitorDetailsButton->setObjectName(QStringLiteral("saveVisitorDetailsButton"));
        saveVisitorDetailsButton->setEnabled(false);

        visitorDetailsLayout->addWidget(saveVisitorDetailsButton);


        horizontalLayout_10->addLayout(visitorDetailsLayout);


        horizontalLayout_3->addWidget(visitorDetailsFrame);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Visitors", 0));
        label_11->setText(QApplication::translate("MainWindow", "Section:", 0));
        settingsButton->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "Search for visitors:", 0));
        quickSearchEdit->setPlaceholderText(QApplication::translate("MainWindow", "Visitor name to find or create", 0));
        addVisitorButton->setText(QApplication::translate("MainWindow", "Create", 0));
        label_9->setText(QApplication::translate("MainWindow", "Visitor name:", 0));
        visitorNameEdit->setText(QString());
        visitorNameEdit->setPlaceholderText(QApplication::translate("MainWindow", "for ex.: Mark Rudolf Junior", 0));
        label_10->setText(QApplication::translate("MainWindow", "Payments:", 0));
        createOrderButton->setText(QApplication::translate("MainWindow", "Create payment", 0));
        saveVisitorDetailsButton->setText(QApplication::translate("MainWindow", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
