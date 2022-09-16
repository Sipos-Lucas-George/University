//
// Created by lukyl on 12/06/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Search.h" resolved

#include "search.h"
#include "ui_Search.h"


Search::Search(QuestionRepo& qRepo, AnswerRepo& aRepo, QWidget *parent) :
        QWidget(parent), ui(new Ui::Search), qRepo(qRepo), aRepo(aRepo) {
    ui->setupUi(this);
    qRepo.sort();
    aRepo.sort();
    this->populate();
    this->connect();
}

Search::~Search() {
    delete ui;
}

void Search::populate() {
    this->ui->listWidget->clear();
    int index = 0;
    for(const auto& i : qRepo.getAll()){
        QListWidgetItem *item = new QListWidgetItem;
        QString str = QString::fromStdString(std::to_string(i.getId()) + " " + i.getName() + " : " + i.getText());
        int k = 3;
        for(const auto& a : aRepo.getAll()) {
            if (k == 0)
                break;
            if (this->qRepo[index].getId() == a.getQid()) {
                str += QString::fromStdString("\n\t" + std::to_string(a.getId()) + " "
                                                    + a.getNameWhoAsked() + " : " + a.getText()
                                                     + " votes: " + std::to_string(a.getNumberOfVotes()));
            }
            --k;
        }
        item->setText(str);
        ui->listWidget->addItem(item);
        ++index;
    }
}

void Search::connect() {
    QObject::connect(ui->lineEdit, &QLineEdit::textChanged, this, [&](){
        this->ui->listWidget->clear();
        int index = 0;
        for(const auto& i : qRepo.getAll()){
            QListWidgetItem *item = new QListWidgetItem;
            QString str = QString::fromStdString(std::to_string(i.getId()) + " " + i.getName() + " : " + i.getText());
            int k = 3;
            for(const auto& a : aRepo.getAll()) {
                if (k == 0)
                    break;
                if (this->qRepo[index].getId() == a.getQid()) {
                    str += QString::fromStdString("\n\t" + std::to_string(a.getId()) + " "
                                                  + a.getNameWhoAsked() + " : " + a.getText()
                                                  + " votes: " + std::to_string(a.getNumberOfVotes()));
                }
                --k;
            }
            item->setText(str);
            ui->listWidget->addItem(item);
            ++index;
        }
    });
}

void Search::update(){
    this->populate();
}

