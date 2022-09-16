/********************************************************************************
** Form generated from reading UI file 'TotalWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOTALWIDGET_H
#define UI_TOTALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TotalWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *noProducts;
    QLabel *label_2;
    QLabel *totalSum;

    void setupUi(QWidget *TotalWidget)
    {
        if (TotalWidget->objectName().isEmpty())
            TotalWidget->setObjectName(QString::fromUtf8("TotalWidget"));
        TotalWidget->resize(398, 115);
        horizontalLayout = new QHBoxLayout(TotalWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(TotalWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        noProducts = new QLabel(TotalWidget);
        noProducts->setObjectName(QString::fromUtf8("noProducts"));
        noProducts->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, noProducts);

        label_2 = new QLabel(TotalWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        totalSum = new QLabel(TotalWidget);
        totalSum->setObjectName(QString::fromUtf8("totalSum"));
        totalSum->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, totalSum);


        horizontalLayout->addLayout(formLayout);


        retranslateUi(TotalWidget);

        QMetaObject::connectSlotsByName(TotalWidget);
    } // setupUi

    void retranslateUi(QWidget *TotalWidget)
    {
        TotalWidget->setWindowTitle(QCoreApplication::translate("TotalWidget", "TotalWidget", nullptr));
        label->setText(QCoreApplication::translate("TotalWidget", "Number of products", nullptr));
        noProducts->setText(QString());
        label_2->setText(QCoreApplication::translate("TotalWidget", "Total sum", nullptr));
        totalSum->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TotalWidget: public Ui_TotalWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTALWIDGET_H
