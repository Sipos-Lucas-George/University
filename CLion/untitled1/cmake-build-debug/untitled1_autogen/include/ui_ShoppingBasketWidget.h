/********************************************************************************
** Form generated from reading UI file 'ShoppingBasketWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGBASKETWIDGET_H
#define UI_SHOPPINGBASKETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShoppingBasketWidget
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *productsListWidget;
    QPushButton *addButton;

    void setupUi(QWidget *ShoppingBasketWidget)
    {
        if (ShoppingBasketWidget->objectName().isEmpty())
            ShoppingBasketWidget->setObjectName(QString::fromUtf8("ShoppingBasketWidget"));
        ShoppingBasketWidget->resize(339, 272);
        verticalLayout = new QVBoxLayout(ShoppingBasketWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        productsListWidget = new QListWidget(ShoppingBasketWidget);
        productsListWidget->setObjectName(QString::fromUtf8("productsListWidget"));
        QFont font;
        font.setPointSize(16);
        productsListWidget->setFont(font);

        verticalLayout->addWidget(productsListWidget);

        addButton = new QPushButton(ShoppingBasketWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setFont(font);

        verticalLayout->addWidget(addButton);


        retranslateUi(ShoppingBasketWidget);

        QMetaObject::connectSlotsByName(ShoppingBasketWidget);
    } // setupUi

    void retranslateUi(QWidget *ShoppingBasketWidget)
    {
        ShoppingBasketWidget->setWindowTitle(QCoreApplication::translate("ShoppingBasketWidget", "ShoppingBasketWidget", nullptr));
        addButton->setText(QCoreApplication::translate("ShoppingBasketWidget", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShoppingBasketWidget: public Ui_ShoppingBasketWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGBASKETWIDGET_H
