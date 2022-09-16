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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *feed;
    QVBoxLayout *verticalLayout;
    QListWidget *posts;
    QFormLayout *formLayout;
    QPushButton *update_2;
    QLineEdit *update;
    QVBoxLayout *verticalLayout_2;
    QListWidget *topic;
    QFormLayout *formLayout_2;
    QPushButton *subscribe;
    QLineEdit *search;

    void setupUi(QWidget *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName(QString::fromUtf8("UserWindow"));
        UserWindow->resize(1021, 417);
        horizontalLayout = new QHBoxLayout(UserWindow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        feed = new QListWidget(UserWindow);
        feed->setObjectName(QString::fromUtf8("feed"));

        horizontalLayout->addWidget(feed);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        posts = new QListWidget(UserWindow);
        posts->setObjectName(QString::fromUtf8("posts"));

        verticalLayout->addWidget(posts);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        update_2 = new QPushButton(UserWindow);
        update_2->setObjectName(QString::fromUtf8("update_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, update_2);

        update = new QLineEdit(UserWindow);
        update->setObjectName(QString::fromUtf8("update"));

        formLayout->setWidget(0, QFormLayout::FieldRole, update);


        verticalLayout->addLayout(formLayout);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        topic = new QListWidget(UserWindow);
        topic->setObjectName(QString::fromUtf8("topic"));

        verticalLayout_2->addWidget(topic);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        subscribe = new QPushButton(UserWindow);
        subscribe->setObjectName(QString::fromUtf8("subscribe"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, subscribe);

        search = new QLineEdit(UserWindow);
        search->setObjectName(QString::fromUtf8("search"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, search);


        verticalLayout_2->addLayout(formLayout_2);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QWidget *UserWindow)
    {
        update_2->setText(QCoreApplication::translate("UserWindow", "Update", nullptr));
        subscribe->setText(QCoreApplication::translate("UserWindow", "Subscribe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
