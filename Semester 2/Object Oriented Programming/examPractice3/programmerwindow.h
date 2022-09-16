//
// Created by lukyl on 11/06/2022.
//

#ifndef EXAMPRACTICE3_PROGRAMMERWINDOW_H
#define EXAMPRACTICE3_PROGRAMMERWINDOW_H

#include <QWidget>
#include "Observer.h"
#include "TaskRepo.h"
#include "ProgrammerRepo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ProgrammerWindow; }
QT_END_NAMESPACE

class ProgrammerWindow : public QWidget, public Observer {
Q_OBJECT

public:
    explicit ProgrammerWindow(Programmer& p, ProgrammerRepo& pRepo, TaskRepo& repo, QWidget *parent = nullptr);

    ~ProgrammerWindow() override;
    void update() override;
private:
    Ui::ProgrammerWindow *ui;
    ProgrammerRepo& pRepo;
    Programmer programmer;
    TaskRepo& repo;
    void populate();
    void connect();
};


#endif //EXAMPRACTICE3_PROGRAMMERWINDOW_H
