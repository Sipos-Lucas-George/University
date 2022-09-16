//
// Created by lukyl on 23/05/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"


GUI::GUI(Repository& repo, QWidget *parent) :
        QWidget(parent), ui(new Ui::GUI), repo(repo){
    ui->setupUi(this);
    this->populate();
    this->connectSignals();
}

GUI::~GUI() {
    delete ui;
}

void GUI::populate() {
    this->ui->mainList->clear();

    this->repo.sort();
    std::vector<Task> tasks = this->repo.getAll();
    for (auto task: tasks) {
        this->ui->mainList->addItem(QString::fromStdString(task.getDes() + ", " + std::to_string(task.getDur())
                                                           + ", " + std::to_string(task.getPri())));
    }
}

void GUI::connectSignals() {
    QObject::connect(this->ui->filterButton, &QPushButton::clicked, this, &GUI::filter);
}

void GUI::filter() {
    std::string word = this->ui->lineEdit->text().toStdString();
    if (word.empty()) {
        this->populate();
        return;
    }
    this->repo.sort();
    std::vector<Task> tasks = this->repo.getAll();
    this->ui->mainList->clear();
    for (auto task: tasks) {
        std::string toShow = task.getDes() + ", " + std::to_string(task.getDur())
                             + ", " + std::to_string(task.getPri());
        if(task.getPri() == stoi(word))
            this->ui->mainList->addItem(QString::fromStdString(toShow));
    }
}

