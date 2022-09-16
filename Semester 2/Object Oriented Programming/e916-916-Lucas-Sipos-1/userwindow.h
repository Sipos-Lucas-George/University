//
// Created by lukyl on 12/06/2022.
//

#ifndef E916_916_LUCAS_SIPOS_1_USERWINDOW_H
#define E916_916_LUCAS_SIPOS_1_USERWINDOW_H

#include <QWidget>
#include "Observer.h"
#include "QuestionRepo.h"
#include "AnswerRepo.h"
#include "User.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UserWindow; }
QT_END_NAMESPACE

class UserWindow : public QWidget, public Observer {
Q_OBJECT

public:
    explicit UserWindow(User& user, QuestionRepo& qRepo, AnswerRepo& aRepo, QWidget *parent = nullptr);

    ~UserWindow() override;

private:
    Ui::UserWindow *ui;
    User user;
    QuestionRepo& qRepo;
    AnswerRepo& aRepo;
    void populate();
    void connect();
    void update() override;
};


#endif //E916_916_LUCAS_SIPOS_1_USERWINDOW_H
