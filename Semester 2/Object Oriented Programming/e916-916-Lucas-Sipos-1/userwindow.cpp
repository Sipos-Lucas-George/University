//
// Created by lukyl on 12/06/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UserWindow.h" resolved

#include "userwindow.h"
#include "ui_UserWindow.h"


UserWindow::UserWindow(User& user, QuestionRepo& qRepo, AnswerRepo& aRepo, QWidget *parent) :
        QWidget(parent), ui(new Ui::UserWindow), user(user), qRepo(qRepo), aRepo(aRepo) {
    this->setWindowTitle(QCoreApplication::translate("UserWindow", user.getName().c_str(), nullptr));
    ui->setupUi(this);
    qRepo.addObserver(this);
    aRepo.addObserver(this);
    aRepo.sort();
    qRepo.sort();
    this->populate();
    this->connect();
}


UserWindow::~UserWindow() {
    delete ui;
}

void UserWindow::populate() {
    ui->listWidget1->clear();
    for(const auto& i : qRepo.getAll()){
        ui->listWidget1->addItem(QString::fromStdString(std::to_string(i.getId()) + " " + i.getName() + " : " + i.getText()));
    }
}

void UserWindow::connect() {
    QObject::connect(ui->listWidget1, &QListWidget::itemSelectionChanged, this, [&](){
        aRepo.sort();
        qRepo.sort();
        ui->listWidget2->clear();
        int index = ui->listWidget1->currentRow();
        for(const auto& i : aRepo.getAll()){
            if(this->qRepo[index].getId() == i.getQid()){
                QListWidgetItem *item = new QListWidgetItem;
                item->setText(QString::fromStdString(std::to_string(i.getId()) + " "
                + i.getNameWhoAsked() + " : " + i.getText()
                + " votes: " + std::to_string(i.getNumberOfVotes())));
                ui->listWidget2->addItem(item);
            if(this->qRepo[index].getId() == i.getQid() && this->user.getName() == i.getNameWhoAsked())
                item->setBackground(Qt::yellow);
            }
        }//int id, int qId, const std::string &nameWhoAsked, const std::string &text, int numberOfVotes
    });
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, [&](){
        aRepo.sort();
        qRepo.sort();
        if(ui->lineEdit->text().isEmpty())
            return;
        this->qRepo.addQuestion(Question(this->qRepo.getHighestID() + 1,ui->lineEdit->text().toStdString(), this->user.getName()));
    });
    QObject::connect(ui->pushButton2, &QPushButton::clicked, this, [&](){
        aRepo.sort();
        qRepo.sort();
        int index = this->ui->listWidget1->currentRow();
        if(ui->lineEdit2->text().isEmpty())
            return;
        this->aRepo.addAnswer(Answer(this->aRepo.getHighestID() + 1, this->qRepo[index].getId(), this->user.getName(),
                                     ui->lineEdit2->text().toStdString(), 0));
    });//int id, int qId, const std::string &nameWhoAsked, const std::string &text, int numberOfVotes
}

void UserWindow::update() {
    this->populate();
}

