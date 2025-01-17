/********************************************************************************
** Form generated from reading UI file 'createorderwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEORDERWINDOW_H
#define UI_CREATEORDERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateOrderWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *programsList;
    QLabel *label_2;
    QDoubleSpinBox *amountEdit;
    QLabel *label_3;
    QCalendarWidget *datePicker;
    QHBoxLayout *horizontalLayout;
    QPushButton *createOrderButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *CreateOrderWindow)
    {
        if (CreateOrderWindow->objectName().isEmpty())
            CreateOrderWindow->setObjectName(QStringLiteral("CreateOrderWindow"));
        CreateOrderWindow->resize(561, 388);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/yesport_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreateOrderWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(CreateOrderWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(CreateOrderWindow);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        programsList = new QComboBox(CreateOrderWindow);
        programsList->setObjectName(QStringLiteral("programsList"));

        verticalLayout->addWidget(programsList);

        label_2 = new QLabel(CreateOrderWindow);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        amountEdit = new QDoubleSpinBox(CreateOrderWindow);
        amountEdit->setObjectName(QStringLiteral("amountEdit"));
        amountEdit->setMaximum(9999.99);

        verticalLayout->addWidget(amountEdit);

        label_3 = new QLabel(CreateOrderWindow);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        datePicker = new QCalendarWidget(CreateOrderWindow);
        datePicker->setObjectName(QStringLiteral("datePicker"));

        verticalLayout->addWidget(datePicker);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        createOrderButton = new QPushButton(CreateOrderWindow);
        createOrderButton->setObjectName(QStringLiteral("createOrderButton"));

        horizontalLayout->addWidget(createOrderButton);

        cancelButton = new QPushButton(CreateOrderWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(CreateOrderWindow);

        QMetaObject::connectSlotsByName(CreateOrderWindow);
    } // setupUi

    void retranslateUi(QWidget *CreateOrderWindow)
    {
        CreateOrderWindow->setWindowTitle(QApplication::translate("CreateOrderWindow", "Payment", 0));
        label->setText(QApplication::translate("CreateOrderWindow", "Service type:", 0));
        label_2->setText(QApplication::translate("CreateOrderWindow", "Amount:", 0));
        label_3->setText(QApplication::translate("CreateOrderWindow", "Payed until:", 0));
        createOrderButton->setText(QApplication::translate("CreateOrderWindow", "Confirm", 0));
        cancelButton->setText(QApplication::translate("CreateOrderWindow", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateOrderWindow: public Ui_CreateOrderWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEORDERWINDOW_H
