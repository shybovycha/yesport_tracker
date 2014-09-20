/********************************************************************************
** Form generated from reading UI file 'visitordetailswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISITORDETAILSWINDOW_H
#define UI_VISITORDETAILSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisitorDetailsWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *visitorNameEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *createOrderButton;
    QListWidget *listWidget;
    QPushButton *closeButton;

    void setupUi(QWidget *VisitorDetailsWindow)
    {
        if (VisitorDetailsWindow->objectName().isEmpty())
            VisitorDetailsWindow->setObjectName(QStringLiteral("VisitorDetailsWindow"));
        VisitorDetailsWindow->resize(618, 429);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/yesport_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        VisitorDetailsWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(VisitorDetailsWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(VisitorDetailsWindow);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        visitorNameEdit = new QLineEdit(VisitorDetailsWindow);
        visitorNameEdit->setObjectName(QStringLiteral("visitorNameEdit"));

        verticalLayout->addWidget(visitorNameEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(VisitorDetailsWindow);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        createOrderButton = new QPushButton(VisitorDetailsWindow);
        createOrderButton->setObjectName(QStringLiteral("createOrderButton"));

        horizontalLayout->addWidget(createOrderButton);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(VisitorDetailsWindow);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        closeButton = new QPushButton(VisitorDetailsWindow);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        verticalLayout->addWidget(closeButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(VisitorDetailsWindow);

        QMetaObject::connectSlotsByName(VisitorDetailsWindow);
    } // setupUi

    void retranslateUi(QWidget *VisitorDetailsWindow)
    {
        VisitorDetailsWindow->setWindowTitle(QApplication::translate("VisitorDetailsWindow", "\320\222\321\226\320\264\320\262\321\226\320\264\321\203\320\262\320\260\321\207", 0));
        label->setText(QApplication::translate("VisitorDetailsWindow", "\320\206\320\274\342\200\231\321\217 \321\202\320\260 \320\277\321\200\321\226\320\267\320\262\320\270\321\211\320\265 \320\262\321\226\320\264\320\262\321\226\320\264\321\203\320\262\320\260\321\207\320\260:", 0));
        visitorNameEdit->setText(QString());
        visitorNameEdit->setPlaceholderText(QApplication::translate("VisitorDetailsWindow", "\320\275\320\260\320\277\321\200. \320\206\320\262\320\260\320\275\320\276\320\262 \320\241\321\202\320\265\320\277\320\260\320\275 \320\237\320\265\321\202\321\200\320\276\320\262\320\270\321\207", 0));
        label_2->setText(QApplication::translate("VisitorDetailsWindow", "\320\236\320\277\320\273\320\260\321\207\320\265\320\275\321\226 \320\277\320\276\321\201\320\273\321\203\320\263\320\270:", 0));
        createOrderButton->setText(QApplication::translate("VisitorDetailsWindow", "\320\224\320\276\320\264\320\260\321\202\320\270", 0));
        closeButton->setText(QApplication::translate("VisitorDetailsWindow", "\320\227\320\260\320\272\321\200\320\270\321\202\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class VisitorDetailsWindow: public Ui_VisitorDetailsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISITORDETAILSWINDOW_H
