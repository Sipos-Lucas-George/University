/********************************************************************************
** Form generated from reading UI file 'programmerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMMERWINDOW_H
#define UI_PROGRAMMERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgrammerWindow
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QLineEdit *lineEdit1;
    QGridLayout *gridLayout;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QPushButton *pushButton4;

    void setupUi(QWidget *ProgrammerWindow)
    {
        if (ProgrammerWindow->objectName().isEmpty())
            ProgrammerWindow->setObjectName(QString::fromUtf8("ProgrammerWindow"));
        ProgrammerWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(ProgrammerWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(ProgrammerWindow);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        lineEdit1 = new QLineEdit(ProgrammerWindow);
        lineEdit1->setObjectName(QString::fromUtf8("lineEdit1"));

        verticalLayout->addWidget(lineEdit1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton1 = new QPushButton(ProgrammerWindow);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));

        gridLayout->addWidget(pushButton1, 0, 0, 1, 1);

        pushButton2 = new QPushButton(ProgrammerWindow);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));

        gridLayout->addWidget(pushButton2, 0, 1, 1, 1);

        pushButton3 = new QPushButton(ProgrammerWindow);
        pushButton3->setObjectName(QString::fromUtf8("pushButton3"));

        gridLayout->addWidget(pushButton3, 1, 0, 1, 1);

        pushButton4 = new QPushButton(ProgrammerWindow);
        pushButton4->setObjectName(QString::fromUtf8("pushButton4"));

        gridLayout->addWidget(pushButton4, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ProgrammerWindow);

        QMetaObject::connectSlotsByName(ProgrammerWindow);
    } // setupUi

    void retranslateUi(QWidget *ProgrammerWindow)
    {
        pushButton1->setText(QCoreApplication::translate("ProgrammerWindow", "Add", nullptr));
        pushButton2->setText(QCoreApplication::translate("ProgrammerWindow", "Delete", nullptr));
        pushButton3->setText(QCoreApplication::translate("ProgrammerWindow", "Start", nullptr));
        pushButton4->setText(QCoreApplication::translate("ProgrammerWindow", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgrammerWindow: public Ui_ProgrammerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMMERWINDOW_H
