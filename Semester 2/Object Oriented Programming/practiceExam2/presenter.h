//
// Created by lukyl on 10/06/2022.
//

#ifndef PRACTICEEXAM2_PRESENTER_H
#define PRACTICEEXAM2_PRESENTER_H

#include <QWidget>
#include "Observer.h"
#include "QuestionRepo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Presenter; }
QT_END_NAMESPACE

class Presenter : public QWidget, public Observer{
Q_OBJECT

public:
    explicit Presenter(QuestionRepo& r, QWidget *parent = nullptr);

    ~Presenter() override;


private:
    Ui::Presenter *ui;
    QuestionRepo& list;
    void connect();
    void populate();
    void update() override;

};

#endif //PRACTICEEXAM2_PRESENTER_H
