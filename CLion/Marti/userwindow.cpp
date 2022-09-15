//
// Created by lukyl on 06/07/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UserWindow.h" resolved

#include "userwindow.h"
#include "ui_UserWindow.h"


UserWindow::UserWindow(User& user, RepoTopics& topics, RepoPosts& posts, QWidget *parent) :
        QWidget(parent), ui(new Ui::UserWindow), user(user), topics(topics), posts(posts){
    this->setWindowTitle(QCoreApplication::translate("UserWindow", user.getName().c_str(), nullptr));
    ui->setupUi(this);
    topics.addObserver(this);
    posts.addObserver(this);
    posts.sort();
    this->populate();
    this->connect();
}

UserWindow::~UserWindow() {
    delete ui;
}

void UserWindow::update() {
    this->populate();
}

void UserWindow::populate() {
    ui->feed->clear();
    ui->topic->clear();
    ui->posts->clear();
    for(auto i : posts.getAll()){
        if (i.findTopic(this->topics.getAll(), user.getName()) || i.getText().find(user.getName()) != std::string::npos)
            ui->feed->addItem(QString::fromStdString(i.getText()));
    }
    for(auto i : posts.getAll()){
        if (i.getUser().getName() == user.getName())
            ui->posts->addItem(QString::fromStdString(i.getText()));
    }
    for (auto i : topics.getAll()){
        if (i.findName(user.getName()))
            ui->topic->addItem(QString::fromStdString(i.getTopic()));
    }
}

void UserWindow::connect() {
    QObject::connect(ui->subscribe, &QPushButton::clicked, this, [&](){
        int index = this->ui->topic->currentRow();
        std::string text = ui->topic->item(index)->text().toStdString();
        for (int i = 0; i < topics.getAll().size(); ++i){
            if (topics[i].getTopic() == text){
                topics[i].addList(user);
                return;
            }
        }
    });
    QObject::connect(ui->search, &QLineEdit::textChanged, this, [&]() {
        if (ui->search->text().isEmpty())
            this->populate();
        else{
            ui->topic->clear();

            std::string text = this->ui->search->text().toStdString();
            for (auto& i : topics.getAll()){
                if (i.getTopic().find(text) != std::string::npos)
                    ui->topic->addItem(QString::fromStdString(i.getTopic()));
            }
        }
    });
}

