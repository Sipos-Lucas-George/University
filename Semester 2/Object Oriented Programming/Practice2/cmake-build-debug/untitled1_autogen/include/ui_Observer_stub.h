/********************************************************************************
** Form generated from reading UI file 'Observer_stub.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBSERVER_STUB_H
#define UI_OBSERVER_STUB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Observer_stubClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Observer_stubClass)
    {
        if (Observer_stubClass->objectName().isEmpty())
            Observer_stubClass->setObjectName(QString::fromUtf8("Observer_stubClass"));
        Observer_stubClass->resize(600, 400);
        menuBar = new QMenuBar(Observer_stubClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Observer_stubClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Observer_stubClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Observer_stubClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Observer_stubClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Observer_stubClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Observer_stubClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Observer_stubClass->setStatusBar(statusBar);

        retranslateUi(Observer_stubClass);

        QMetaObject::connectSlotsByName(Observer_stubClass);
    } // setupUi

    void retranslateUi(QMainWindow *Observer_stubClass)
    {
        Observer_stubClass->setWindowTitle(QCoreApplication::translate("Observer_stubClass", "Observer_stub", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Observer_stubClass: public Ui_Observer_stubClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBSERVER_STUB_H
