/********************************************************************************
** Form generated from reading UI file 'Lecture10_genes.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE10_GENES_H
#define UI_LECTURE10_GENES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lecture10_genesClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture10_genesClass)
    {
        if (Lecture10_genesClass->objectName().isEmpty())
            Lecture10_genesClass->setObjectName(QString::fromUtf8("Lecture10_genesClass"));
        Lecture10_genesClass->resize(600, 400);
        menuBar = new QMenuBar(Lecture10_genesClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Lecture10_genesClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture10_genesClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Lecture10_genesClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lecture10_genesClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Lecture10_genesClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lecture10_genesClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Lecture10_genesClass->setStatusBar(statusBar);

        retranslateUi(Lecture10_genesClass);

        QMetaObject::connectSlotsByName(Lecture10_genesClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture10_genesClass)
    {
        Lecture10_genesClass->setWindowTitle(QCoreApplication::translate("Lecture10_genesClass", "Lecture10_genes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lecture10_genesClass: public Ui_Lecture10_genesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE10_GENES_H
