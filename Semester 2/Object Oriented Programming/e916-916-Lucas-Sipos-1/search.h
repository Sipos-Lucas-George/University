//
// Created by lukyl on 12/06/2022.
//

#ifndef E916_916_LUCAS_SIPOS_1_SEARCH_H
#define E916_916_LUCAS_SIPOS_1_SEARCH_H

#include <QWidget>
#include "Observer.h"
#include "QuestionRepo.h"
#include "AnswerRepo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Search; }
QT_END_NAMESPACE

class Search : public QWidget, public Observer{
Q_OBJECT

public:
    explicit Search(QuestionRepo& qRepo, AnswerRepo& aRepo, QWidget *parent = nullptr);

    ~Search() override;

private:
    Ui::Search *ui;
    QuestionRepo& qRepo;
    AnswerRepo& aRepo;

    void populate();
    void connect();
    void update() override;
};


#endif //E916_916_LUCAS_SIPOS_1_SEARCH_H
