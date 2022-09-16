/********************************************************************************
** Form generated from reading UI file 'Lecture10_demo.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE10_DEMO_H
#define UI_LECTURE10_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lecture10_demoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture10_demoClass)
    {
        if (Lecture10_demoClass->objectName().isEmpty())
            Lecture10_demoClass->setObjectName(QString::fromUtf8("Lecture10_demoClass"));
        Lecture10_demoClass->resize(600, 400);
        menuBar = new QMenuBar(Lecture10_demoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Lecture10_demoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture10_demoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Lecture10_demoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lecture10_demoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Lecture10_demoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lecture10_demoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Lecture10_demoClass->setStatusBar(statusBar);

        retranslateUi(Lecture10_demoClass);

        QMetaObject::connectSlotsByName(Lecture10_demoClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture10_demoClass)
    {
        Lecture10_demoClass->setWindowTitle(QCoreApplication::translate("Lecture10_demoClass", "Lecture10_demo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lecture10_demoClass: public Ui_Lecture10_demoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE10_DEMO_H
