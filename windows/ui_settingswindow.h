/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *departmentsTab;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QToolButton *addDepartmentButton;
    QToolButton *removeDepartmentButton;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLineEdit *departmentNameEdit;
    QListWidget *departmentsList;
    QWidget *programsTab;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QLineEdit *programNameEdit;
    QListWidget *programsList;
    QVBoxLayout *verticalLayout_3;
    QToolButton *addProgramButton;
    QToolButton *removeProgramButton;
    QPushButton *closeButton;

    void setupUi(QWidget *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QStringLiteral("SettingsWindow"));
        SettingsWindow->resize(605, 367);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/yesport_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsWindow->setWindowIcon(icon);
        SettingsWindow->setToolTipDuration(5000);
        SettingsWindow->setStyleSheet(QStringLiteral(""));
        gridLayout_3 = new QGridLayout(SettingsWindow);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget = new QTabWidget(SettingsWindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        departmentsTab = new QWidget();
        departmentsTab->setObjectName(QStringLiteral("departmentsTab"));
        gridLayout = new QGridLayout(departmentsTab);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addDepartmentButton = new QToolButton(departmentsTab);
        addDepartmentButton->setObjectName(QStringLiteral("addDepartmentButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/images/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addDepartmentButton->setIcon(icon1);
        addDepartmentButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(addDepartmentButton);

        removeDepartmentButton = new QToolButton(departmentsTab);
        removeDepartmentButton->setObjectName(QStringLiteral("removeDepartmentButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/images/Remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeDepartmentButton->setIcon(icon2);
        removeDepartmentButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(removeDepartmentButton);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(departmentsTab);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_4->addWidget(label);

        departmentNameEdit = new QLineEdit(departmentsTab);
        departmentNameEdit->setObjectName(QStringLiteral("departmentNameEdit"));
        departmentNameEdit->setToolTipDuration(5000);

        verticalLayout_4->addWidget(departmentNameEdit);

        departmentsList = new QListWidget(departmentsTab);
        departmentsList->setObjectName(QStringLiteral("departmentsList"));

        verticalLayout_4->addWidget(departmentsList);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        tabWidget->addTab(departmentsTab, QString());
        programsTab = new QWidget();
        programsTab->setObjectName(QStringLiteral("programsTab"));
        gridLayout_2 = new QGridLayout(programsTab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_2 = new QLabel(programsTab);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_5->addWidget(label_2);

        programNameEdit = new QLineEdit(programsTab);
        programNameEdit->setObjectName(QStringLiteral("programNameEdit"));

        verticalLayout_5->addWidget(programNameEdit);

        programsList = new QListWidget(programsTab);
        programsList->setObjectName(QStringLiteral("programsList"));

        verticalLayout_5->addWidget(programsList);


        gridLayout_2->addLayout(verticalLayout_5, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        addProgramButton = new QToolButton(programsTab);
        addProgramButton->setObjectName(QStringLiteral("addProgramButton"));
        addProgramButton->setIcon(icon1);
        addProgramButton->setIconSize(QSize(24, 24));

        verticalLayout_3->addWidget(addProgramButton);

        removeProgramButton = new QToolButton(programsTab);
        removeProgramButton->setObjectName(QStringLiteral("removeProgramButton"));
        removeProgramButton->setIcon(icon2);
        removeProgramButton->setIconSize(QSize(24, 24));

        verticalLayout_3->addWidget(removeProgramButton);


        gridLayout_2->addLayout(verticalLayout_3, 0, 2, 1, 1);

        tabWidget->addTab(programsTab, QString());

        verticalLayout_2->addWidget(tabWidget);

        closeButton = new QPushButton(SettingsWindow);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        verticalLayout_2->addWidget(closeButton);


        gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(SettingsWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "\320\235\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\320\275\320\275\321\217", 0));
        addDepartmentButton->setText(QString());
        removeDepartmentButton->setText(QString());
        label->setText(QApplication::translate("SettingsWindow", "\320\235\320\260\320\267\320\262\320\260 \321\201\320\265\320\272\321\206\321\226\321\227:", 0));
#ifndef QT_NO_TOOLTIP
        departmentNameEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        departmentNameEdit->setPlaceholderText(QApplication::translate("SettingsWindow", "\320\275\320\260\320\277\321\200. \"\320\231\320\276\320\263\320\260\"", 0));
        tabWidget->setTabText(tabWidget->indexOf(departmentsTab), QApplication::translate("SettingsWindow", "\320\241\320\265\320\272\321\206\321\226\321\227", 0));
        label_2->setText(QApplication::translate("SettingsWindow", "\320\222\320\270\320\264 \320\277\320\276\321\201\320\273\321\203\320\263\320\270:", 0));
        programNameEdit->setPlaceholderText(QApplication::translate("SettingsWindow", "\320\275\320\260\320\277\321\200. \"\320\234\321\226\321\201\321\217\321\207\320\275\320\270\320\271 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202\"", 0));
        addProgramButton->setText(QString());
        removeProgramButton->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(programsTab), QApplication::translate("SettingsWindow", "\320\237\320\276\321\201\320\273\321\203\320\263\320\270", 0));
        closeButton->setText(QApplication::translate("SettingsWindow", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
