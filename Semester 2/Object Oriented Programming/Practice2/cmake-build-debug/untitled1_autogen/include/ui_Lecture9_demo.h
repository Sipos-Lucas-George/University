/********************************************************************************
** Form generated from reading UI file 'Lecture9_demo.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE9_DEMO_H
#define UI_LECTURE9_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lecture9_demoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture9_demoClass)
    {
        if (Lecture9_demoClass->objectName().isEmpty())
            Lecture9_demoClass->setObjectName(QString::fromUtf8("Lecture9_demoClass"));
        Lecture9_demoClass->resize(600, 400);
        menuBar = new QMenuBar(Lecture9_demoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Lecture9_demoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture9_demoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Lecture9_demoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lecture9_demoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Lecture9_demoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lecture9_demoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Lecture9_demoClass->setStatusBar(statusBar);

        retranslateUi(Lecture9_demoClass);

        QMetaObject::connectSlotsByName(Lecture9_demoClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture9_demoClass)
    {
        Lecture9_demoClass->setWindowTitle(QCoreApplication::translate("Lecture9_demoClass", "Lecture9_demo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lecture9_demoClass: public Ui_Lecture9_demoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE9_DEMO_H
