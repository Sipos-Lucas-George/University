//
// Created by lukyl on 10/06/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_User.h" resolved

#include "user.h"
#include "ui_User.h"


User::User(QuestionRepo& q, ParticipantRepo& par, Participant& p, QWidget *parent) :
        QWidget(parent), ui(new Ui::User), qList(q), participant(p), repo(par) {
    this->setWindowTitle(QCoreApplication::translate("User", participant.getName().c_str(), nullptr));
    ui->setupUi(this);
    qList.addObserver(this);
    for(auto l : qList.getAll())
        answer.push_back(-1);
    this->populate();
    this->connect();
}

User::~User() {
    delete ui;
}

void User::populate() {
    this->ui->listWidget->clear();
    for (auto q : qList.getAll())
        this->ui->listWidget->addItem(QString::fromStdString(q.toString()));
}

void User::connect() {
    QObject::connect(this->ui->listWidget, &QListWidget::itemSelectionChanged, this, [&](){
        int index = this->ui->listWidget->currentRow();
        if(this->answer[index] != -1)
            this->ui->pushButton->setDisabled(true);
        else
            this->ui->pushButton->setEnabled(true);
    });
    QObject::connect(this->ui->pushButton, &QPushButton::clicked, this, [&]() {
        int index = this->ui->listWidget->currentRow();
        this->answer[index]++;
        this->ui->pushButton->setDisabled(true);
        if(this->ui->lineEdit->text().toStdString() == this->qList.getAll()[index].getAnswer()){
            this->answer[index]++;
            this->ui->listWidget->currentItem()->setBackground(Qt::green);
            this->participant.setScore(this->participant.getScore() + this->qList.getAll()[index].getScore());
            this->repo.writeFile();
        }
        else
            this->ui->listWidget->currentItem()->setBackground(Qt::red);
    });
}

void User::update() {
    this->populate();
    this->answer.push_back(-1);
}

