/********************************************************************************
** Form generated from reading UI file 'ModelView_stub.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELVIEW_STUB_H
#define UI_MODELVIEW_STUB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelView_stubClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ModelView_stubClass)
    {
        if (ModelView_stubClass->objectName().isEmpty())
            ModelView_stubClass->setObjectName(QString::fromUtf8("ModelView_stubClass"));
        ModelView_stubClass->resize(600, 400);
        menuBar = new QMenuBar(ModelView_stubClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ModelView_stubClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ModelView_stubClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ModelView_stubClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ModelView_stubClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ModelView_stubClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ModelView_stubClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ModelView_stubClass->setStatusBar(statusBar);

        retranslateUi(ModelView_stubClass);

        QMetaObject::connectSlotsByName(ModelView_stubClass);
    } // setupUi

    void retranslateUi(QMainWindow *ModelView_stubClass)
    {
        ModelView_stubClass->setWindowTitle(QCoreApplication::translate("ModelView_stubClass", "ModelView_stub", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelView_stubClass: public Ui_ModelView_stubClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELVIEW_STUB_H
