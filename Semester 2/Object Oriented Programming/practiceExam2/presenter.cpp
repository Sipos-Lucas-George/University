//
// Created by lukyl on 10/06/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Presenter.h" resolved

#include "presenter.h"
#include "ui_Presenter.h"


Presenter::Presenter(QuestionRepo& r, QWidget *parent) :
        QWidget(parent), ui(new Ui::Presenter), list(r){
    ui->setupUi(this);
    this->populate();
    this->connect();
}

Presenter::~Presenter() {
    delete ui;
}

void Presenter::connect() {
    QObject::connect(this->ui->pushButton, &QPushButton::clicked, this, [&](){
        Question q(this->ui->lineEdit1->text().toInt(),this->ui->lineEdit2->text().toStdString(), this->ui->lineEdit3->text().toStdString(), this->ui->lineEdit4->text().toInt());
        this->list.addQuestion(q);
        this->populate();
    });
}

void Presenter::populate() {
    this->ui->listWidget->clear();
    for (auto q : list.getAll())
        this->ui->listWidget->addItem(QString::fromStdString(q.toString()));
}

void Presenter::update() {
    this->populate();
}

