/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *mainList;
    QLineEdit *lineEdit;
    QPushButton *filterButton;

    void setupUi(QWidget *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QString::fromUtf8("GUI"));
        GUI->resize(577, 385);
        verticalLayout = new QVBoxLayout(GUI);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mainList = new QListWidget(GUI);
        mainList->setObjectName(QString::fromUtf8("mainList"));
        QFont font;
        font.setPointSize(12);
        mainList->setFont(font);

        verticalLayout->addWidget(mainList);

        lineEdit = new QLineEdit(GUI);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);

        verticalLayout->addWidget(lineEdit);

        filterButton = new QPushButton(GUI);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        filterButton->setFont(font);

        verticalLayout->addWidget(filterButton);


        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QWidget *GUI)
    {
        GUI->setWindowTitle(QCoreApplication::translate("GUI", "GUI", nullptr));
        filterButton->setText(QCoreApplication::translate("GUI", "Show by priority", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
