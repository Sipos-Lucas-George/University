/********************************************************************************
** Form generated from reading UI file 'TableViewWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEVIEWWIDGET_H
#define UI_TABLEVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableViewWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *productsTableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *clearButton;

    void setupUi(QWidget *TableViewWidget)
    {
        if (TableViewWidget->objectName().isEmpty())
            TableViewWidget->setObjectName(QString::fromUtf8("TableViewWidget"));
        TableViewWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(TableViewWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        productsTableView = new QTableView(TableViewWidget);
        productsTableView->setObjectName(QString::fromUtf8("productsTableView"));
        QFont font;
        font.setPointSize(16);
        productsTableView->setFont(font);

        verticalLayout->addWidget(productsTableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addButton = new QPushButton(TableViewWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setFont(font);

        horizontalLayout->addWidget(addButton);

        clearButton = new QPushButton(TableViewWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setFont(font);

        horizontalLayout->addWidget(clearButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TableViewWidget);

        QMetaObject::connectSlotsByName(TableViewWidget);
    } // setupUi

    void retranslateUi(QWidget *TableViewWidget)
    {
        TableViewWidget->setWindowTitle(QCoreApplication::translate("TableViewWidget", "TableViewWidget", nullptr));
        addButton->setText(QCoreApplication::translate("TableViewWidget", "Add", nullptr));
        clearButton->setText(QCoreApplication::translate("TableViewWidget", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableViewWidget: public Ui_TableViewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEVIEWWIDGET_H
