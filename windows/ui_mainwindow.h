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
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *departmentsList;
    QToolButton *settingsButton;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *quickSearchEdit;
    QPushButton *addVisitorButton;
    QListWidget *usersList;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(605, 398);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/images/yesport_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(MainWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(MainWindow);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        departmentsList = new QComboBox(MainWindow);
        departmentsList->setObjectName(QStringLiteral("departmentsList"));
        departmentsList->setEditable(false);

        horizontalLayout_2->addWidget(departmentsList);

        settingsButton = new QToolButton(MainWindow);
        settingsButton->setObjectName(QStringLiteral("settingsButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/images/Gear Alt.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingsButton->setIcon(icon1);
        settingsButton->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(settingsButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label = new QLabel(MainWindow);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        quickSearchEdit = new QLineEdit(MainWindow);
        quickSearchEdit->setObjectName(QStringLiteral("quickSearchEdit"));
        quickSearchEdit->setAcceptDrops(false);
        quickSearchEdit->setClearButtonEnabled(true);

        horizontalLayout->addWidget(quickSearchEdit);

        addVisitorButton = new QPushButton(MainWindow);
        addVisitorButton->setObjectName(QStringLiteral("addVisitorButton"));
        addVisitorButton->setEnabled(false);

        horizontalLayout->addWidget(addVisitorButton);


        verticalLayout_2->addLayout(horizontalLayout);

        usersList = new QListWidget(MainWindow);
        usersList->setObjectName(QStringLiteral("usersList"));

        verticalLayout_2->addWidget(usersList);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        QWidget::setTabOrder(quickSearchEdit, addVisitorButton);
        QWidget::setTabOrder(addVisitorButton, usersList);
        QWidget::setTabOrder(usersList, departmentsList);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\222\321\226\320\264\320\262\321\226\320\264\321\203\320\262\320\260\321\207\321\226", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\241\320\265\320\272\321\206\321\226\321\217:", 0));
        settingsButton->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\210\321\203\320\272 \320\262\321\226\320\264\320\262\321\226\320\264\321\203\320\262\320\260\321\207\321\226\320\262:", 0));
        quickSearchEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\206\320\274\342\200\231\321\217 \320\260\320\261\320\276 \320\277\321\200\321\226\320\267\320\262\320\270\321\211\320\265 \320\262\321\226\320\264\320\262\321\226\320\264\321\203\320\262\320\260\321\207\320\260, \321\217\320\272\320\276\320\263\320\276 \321\210\321\203\320\272\320\260\321\224\320\274\320\276 \320\260\320\261\320\276 \320\264\320\276\320\264\320\260\321\224\320\274\320\276", 0));
        addVisitorButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
