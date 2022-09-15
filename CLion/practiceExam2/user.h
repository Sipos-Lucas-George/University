//
// Created by lukyl on 10/06/2022.
//

#ifndef PRACTICEEXAM2_USER_H
#define PRACTICEEXAM2_USER_H

#include <QWidget>
#include "Observer.h"
#include "ParticipantRepo.h"
#include "QuestionRepo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class User; }
QT_END_NAMESPACE

class User : public QWidget, public Observer {
Q_OBJECT

public:
    explicit User(QuestionRepo& q, ParticipantRepo& par, Participant& p, QWidget *parent = nullptr);

    ~User() override;

private:
    Ui::User *ui;
    std::vector<int> answer;
    QuestionRepo& qList;
    Participant& participant;
    ParticipantRepo& repo;
    void populate();
    void connect();
    void update() override;
};


#endif //PRACTICEEXAM2_USER_H
