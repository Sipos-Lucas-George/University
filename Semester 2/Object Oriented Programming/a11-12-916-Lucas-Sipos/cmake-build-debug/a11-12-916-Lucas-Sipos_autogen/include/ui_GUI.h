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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QLineEdit *searchLineEdit;
    QListWidget *movieListWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *titleLineEdit;
    QLabel *label_2;
    QLineEdit *genreLineEdit;
    QLabel *label_3;
    QLineEdit *yearLineEdit;
    QLabel *label_5;
    QLineEdit *likesLineEdit;
    QLabel *label_4;
    QLineEdit *trailerLineEdit;
    QGridLayout *gridLayout;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QPushButton *addButton;
    QPushButton *transferButton;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QListWidget *watchListWidget;
    QPushButton *openButton;
    QGridLayout *gridLayout_2;
    QPushButton *likeButton;
    QPushButton *playButton;
    QPushButton *deleteWatchedButton;

    void setupUi(QWidget *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QString::fromUtf8("GUI"));
        GUI->resize(958, 651);
        horizontalLayout_2 = new QHBoxLayout(GUI);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(GUI);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setPointSize(12);
        label_6->setFont(font);

        verticalLayout->addWidget(label_6);

        searchLineEdit = new QLineEdit(GUI);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));
        searchLineEdit->setFont(font);

        verticalLayout->addWidget(searchLineEdit);

        movieListWidget = new QListWidget(GUI);
        movieListWidget->setObjectName(QString::fromUtf8("movieListWidget"));
        movieListWidget->setFont(font);

        verticalLayout->addWidget(movieListWidget);


        verticalLayout_3->addLayout(verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(GUI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        titleLineEdit = new QLineEdit(GUI);
        titleLineEdit->setObjectName(QString::fromUtf8("titleLineEdit"));
        titleLineEdit->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, titleLineEdit);

        label_2 = new QLabel(GUI);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        genreLineEdit = new QLineEdit(GUI);
        genreLineEdit->setObjectName(QString::fromUtf8("genreLineEdit"));
        genreLineEdit->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, genreLineEdit);

        label_3 = new QLabel(GUI);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        yearLineEdit = new QLineEdit(GUI);
        yearLineEdit->setObjectName(QString::fromUtf8("yearLineEdit"));
        yearLineEdit->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, yearLineEdit);

        label_5 = new QLabel(GUI);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        likesLineEdit = new QLineEdit(GUI);
        likesLineEdit->setObjectName(QString::fromUtf8("likesLineEdit"));
        likesLineEdit->setFont(font);

        formLayout->setWidget(3, QFormLayout::FieldRole, likesLineEdit);

        label_4 = new QLabel(GUI);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        trailerLineEdit = new QLineEdit(GUI);
        trailerLineEdit->setObjectName(QString::fromUtf8("trailerLineEdit"));
        trailerLineEdit->setFont(font);

        formLayout->setWidget(4, QFormLayout::FieldRole, trailerLineEdit);


        verticalLayout_3->addLayout(formLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        updateButton = new QPushButton(GUI);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setFont(font);

        gridLayout->addWidget(updateButton, 0, 2, 1, 1);

        deleteButton = new QPushButton(GUI);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setFont(font);

        gridLayout->addWidget(deleteButton, 0, 1, 1, 1);

        addButton = new QPushButton(GUI);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setFont(font);

        gridLayout->addWidget(addButton, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        horizontalLayout->addLayout(verticalLayout_3);

        transferButton = new QPushButton(GUI);
        transferButton->setObjectName(QString::fromUtf8("transferButton"));
        transferButton->setFont(font);

        horizontalLayout->addWidget(transferButton);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_7 = new QLabel(GUI);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout_2->addWidget(label_7);

        watchListWidget = new QListWidget(GUI);
        watchListWidget->setObjectName(QString::fromUtf8("watchListWidget"));
        watchListWidget->setFont(font);

        verticalLayout_2->addWidget(watchListWidget);

        openButton = new QPushButton(GUI);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setFont(font);

        verticalLayout_2->addWidget(openButton);


        verticalLayout_4->addLayout(verticalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        likeButton = new QPushButton(GUI);
        likeButton->setObjectName(QString::fromUtf8("likeButton"));
        likeButton->setFont(font);

        gridLayout_2->addWidget(likeButton, 0, 3, 1, 1);

        playButton = new QPushButton(GUI);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setFont(font);

        gridLayout_2->addWidget(playButton, 0, 0, 1, 1);

        deleteWatchedButton = new QPushButton(GUI);
        deleteWatchedButton->setObjectName(QString::fromUtf8("deleteWatchedButton"));
        deleteWatchedButton->setFont(font);

        gridLayout_2->addWidget(deleteWatchedButton, 0, 2, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);


        horizontalLayout->addLayout(verticalLayout_4);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QWidget *GUI)
    {
        GUI->setWindowTitle(QCoreApplication::translate("GUI", "GUI", nullptr));
        label_6->setText(QCoreApplication::translate("GUI", "Movies", nullptr));
        label->setText(QCoreApplication::translate("GUI", "Title:", nullptr));
        label_2->setText(QCoreApplication::translate("GUI", "Genre:", nullptr));
        label_3->setText(QCoreApplication::translate("GUI", "Year:", nullptr));
        label_5->setText(QCoreApplication::translate("GUI", "Likes:", nullptr));
        label_4->setText(QCoreApplication::translate("GUI", "Trailer:", nullptr));
        updateButton->setText(QCoreApplication::translate("GUI", "Update", nullptr));
        deleteButton->setText(QCoreApplication::translate("GUI", "Delete", nullptr));
        addButton->setText(QCoreApplication::translate("GUI", "Add", nullptr));
        transferButton->setText(QCoreApplication::translate("GUI", ">>>", nullptr));
        label_7->setText(QCoreApplication::translate("GUI", "Watch List", nullptr));
        openButton->setText(QCoreApplication::translate("GUI", "Open", nullptr));
        likeButton->setText(QCoreApplication::translate("GUI", "Like", nullptr));
        playButton->setText(QCoreApplication::translate("GUI", "Play", nullptr));
        deleteWatchedButton->setText(QCoreApplication::translate("GUI", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
