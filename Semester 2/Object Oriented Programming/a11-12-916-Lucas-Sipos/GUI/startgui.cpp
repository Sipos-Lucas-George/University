//
// Created by lukyl on 15/05/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_startGUI.h" resolved

#include "startgui.h"
#include "ui_startGUI.h"
#include "../Repository/Repository.h"
#include "../Service/Service.h"


startGUI::startGUI(QWidget *parent) :
        QWidget(parent), ui(new Ui::startGUI) {
    ui->setupUi(this);
    this->connectSignals();
}

void startGUI::connectSignals(){
    QObject::connect(this->ui->csvButton, &QPushButton::clicked, this, &startGUI::csvPushed);
    QObject::connect(this->ui->htmlButton, &QPushButton::clicked, this, &startGUI::htmlPushed);
}

void startGUI::csvPushed(){
    this->csv = true;
    startGUI::close();
}

void startGUI::htmlPushed(){
    this->csv = false;
    startGUI::close();
}

bool startGUI::csvOrHtml() const{
    return this->csv;
}

startGUI::~startGUI() {
    delete ui;
}

