/********************************************************************************
** Form generated from reading UI file 'startgui.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTGUI_H
#define UI_STARTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startGUI
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *csvButton;
    QPushButton *htmlButton;

    void setupUi(QWidget *startGUI)
    {
        if (startGUI->objectName().isEmpty())
            startGUI->setObjectName(QString::fromUtf8("startGUI"));
        startGUI->resize(400, 300);
        verticalLayout = new QVBoxLayout(startGUI);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(startGUI);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        csvButton = new QPushButton(startGUI);
        csvButton->setObjectName(QString::fromUtf8("csvButton"));
        csvButton->setMaximumSize(QSize(187, 30));
        QFont font1;
        font1.setPointSize(12);
        csvButton->setFont(font1);

        horizontalLayout->addWidget(csvButton);

        htmlButton = new QPushButton(startGUI);
        htmlButton->setObjectName(QString::fromUtf8("htmlButton"));
        htmlButton->setFont(font1);

        horizontalLayout->addWidget(htmlButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(startGUI);

        QMetaObject::connectSlotsByName(startGUI);
    } // setupUi

    void retranslateUi(QWidget *startGUI)
    {
        startGUI->setWindowTitle(QCoreApplication::translate("startGUI", "startGUI", nullptr));
        label->setText(QCoreApplication::translate("startGUI", "Open with CSV / HTML", nullptr));
        csvButton->setText(QCoreApplication::translate("startGUI", "CSV", nullptr));
        htmlButton->setText(QCoreApplication::translate("startGUI", "HTML", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startGUI: public Ui_startGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTGUI_H
