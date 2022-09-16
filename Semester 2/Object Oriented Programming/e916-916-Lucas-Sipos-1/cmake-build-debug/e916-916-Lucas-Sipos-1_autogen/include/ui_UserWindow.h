/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget1;
    QListWidget *listWidget2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit2;
    QPushButton *pushButton2;

    void setupUi(QWidget *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName(QString::fromUtf8("UserWindow"));
        UserWindow->resize(531, 454);
        verticalLayout = new QVBoxLayout(UserWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget1 = new QListWidget(UserWindow);
        listWidget1->setObjectName(QString::fromUtf8("listWidget1"));

        verticalLayout->addWidget(listWidget1);

        listWidget2 = new QListWidget(UserWindow);
        listWidget2->setObjectName(QString::fromUtf8("listWidget2"));

        verticalLayout->addWidget(listWidget2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(UserWindow);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(UserWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);


        verticalLayout->addLayout(formLayout);

        pushButton = new QPushButton(UserWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_2 = new QLabel(UserWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit2 = new QLineEdit(UserWindow);
        lineEdit2->setObjectName(QString::fromUtf8("lineEdit2"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit2);


        verticalLayout->addLayout(formLayout_2);

        pushButton2 = new QPushButton(UserWindow);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));

        verticalLayout->addWidget(pushButton2);


        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QWidget *UserWindow)
    {
        label->setText(QCoreApplication::translate("UserWindow", "Text", nullptr));
        pushButton->setText(QCoreApplication::translate("UserWindow", "Add", nullptr));
        label_2->setText(QCoreApplication::translate("UserWindow", "Answer", nullptr));
        pushButton2->setText(QCoreApplication::translate("UserWindow", "Answer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
