/********************************************************************************
** Form generated from reading UI file 'presenter.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESENTER_H
#define UI_PRESENTER_H

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

class Ui_Presenter
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit1;
    QLabel *label_2;
    QLineEdit *lineEdit2;
    QLabel *label_3;
    QLineEdit *lineEdit3;
    QLabel *label_4;
    QLineEdit *lineEdit4;
    QPushButton *pushButton;

    void setupUi(QWidget *Presenter)
    {
        if (Presenter->objectName().isEmpty())
            Presenter->setObjectName(QString::fromUtf8("Presenter"));
        Presenter->resize(400, 300);
        verticalLayout = new QVBoxLayout(Presenter);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(Presenter);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(Presenter);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit1 = new QLineEdit(Presenter);
        lineEdit1->setObjectName(QString::fromUtf8("lineEdit1"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit1);

        label_2 = new QLabel(Presenter);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit2 = new QLineEdit(Presenter);
        lineEdit2->setObjectName(QString::fromUtf8("lineEdit2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit2);

        label_3 = new QLabel(Presenter);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit3 = new QLineEdit(Presenter);
        lineEdit3->setObjectName(QString::fromUtf8("lineEdit3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit3);

        label_4 = new QLabel(Presenter);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEdit4 = new QLineEdit(Presenter);
        lineEdit4->setObjectName(QString::fromUtf8("lineEdit4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit4);


        verticalLayout->addLayout(formLayout);

        pushButton = new QPushButton(Presenter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(Presenter);

        QMetaObject::connectSlotsByName(Presenter);
    } // setupUi

    void retranslateUi(QWidget *Presenter)
    {
        Presenter->setWindowTitle(QCoreApplication::translate("Presenter", "Presenter", nullptr));
        label->setText(QCoreApplication::translate("Presenter", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("Presenter", "TEXT", nullptr));
        label_3->setText(QCoreApplication::translate("Presenter", "CORRECT ANSWER", nullptr));
        label_4->setText(QCoreApplication::translate("Presenter", "SCORE", nullptr));
        pushButton->setText(QCoreApplication::translate("Presenter", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Presenter: public Ui_Presenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESENTER_H
