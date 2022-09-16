//
// Created by lukyl on 11/06/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ProgrammerWindow.h" resolved

#include "programmerwindow.h"
#include "ui_ProgrammerWindow.h"


ProgrammerWindow::ProgrammerWindow(Programmer& p, ProgrammerRepo& pRepo, TaskRepo& repo, QWidget *parent) :
        QWidget(parent), ui(new Ui::ProgrammerWindow), programmer(p), repo(repo), pRepo(pRepo) {
    this->setWindowTitle(QCoreApplication::translate("ProgrammerWindow", p.getName().c_str(), nullptr));
    ui->setupUi(this);
    this->repo.addObserver(this);
    this->populate();
    this->connect();
}

ProgrammerWindow::~ProgrammerWindow() {
    delete ui;
}

void ProgrammerWindow::populate() {
    this->ui->listWidget->clear();
    this->repo.sort();
    for (const auto& t : this->repo.getAll())
        if (t.getStatus() == "open")
            this->ui->listWidget->addItem(QString::fromStdString(t.getDesc() + " " + t.getStatus()));
        else
            this->ui->listWidget->addItem(QString::fromStdString(t.getDesc() + " " + t.getStatus() + " " + std::to_string(t.getId())) + " " + this->pRepo.getProgrammer(t.getId()).c_str());
}

void ProgrammerWindow::connect() {
    QObject::connect(this->ui->listWidget, &QListWidget::itemSelectionChanged, this, [&](){
        int index = this->ui->listWidget->currentRow();
        if(this->repo[index].getStatus() != "open")
            this->ui->pushButton3->setDisabled(true);
        else
            this->ui->pushButton3->setEnabled(true);
        if(this->repo[index].getStatus() != "in_progress")
            this->ui->pushButton4->setDisabled(true);
        else{
            if(this->repo[index].getId() == this->programmer.getId())
                this->ui->pushButton4->setEnabled(true);
            else
                this->ui->pushButton4->setDisabled(true);
        }
    });
    QObject::connect(this->ui->pushButton1, &QPushButton::clicked, this, [&]() {
        this->repo.addTask(Task(this->ui->lineEdit1->text().toStdString(), "open", 0));
        this->repo.writeFile();
        this->repo.sort();
    });
    QObject::connect(this->ui->pushButton2, &QPushButton::clicked, this, [&]() {
        int index = this->ui->listWidget->currentRow();
        this->repo.deleteTask(index);
        this->repo.writeFile();
        this->repo.sort();
    });
    QObject::connect(this->ui->pushButton3, &QPushButton::clicked, this, [&]() {
        int index = this->ui->listWidget->currentRow();
        this->repo[index].setStatus("in_progress");
        this->repo[index].setId(this->programmer.getId());
        this->repo.notify();
        this->repo.writeFile();
    });
    QObject::connect(this->ui->pushButton4, &QPushButton::clicked, this, [&]() {
        int index = this->ui->listWidget->currentRow();
        this->repo[index].setStatus("done");
        this->repo.notify();
        this->repo.writeFile();
    });
}

void ProgrammerWindow::update() {
    this->populate();
}
