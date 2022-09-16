//
// Created by lukyl on 12/06/2022.
//

#ifndef E916_916_LUCAS_SIPOS_1_ANSWERREPO_H
#define E916_916_LUCAS_SIPOS_1_ANSWERREPO_H
#include "Answer.h"
#include <vector>
#include <algorithm>
#include "Observer.h"

class AnswerRepo : public Subject{
private:
    std::vector<Answer> repo;

public:
    AnswerRepo() { this->readFile(); }
    ~AnswerRepo() = default;
    void addAnswer(const Answer& t) { this->repo.push_back(t); this->sort(); this->writeFile(); this->notify(); }
    void readFile();
    void writeFile();

    int getHighestID();

    std::vector<Answer> getAll() { return this->repo; }
    Answer& operator[](int index) { return this->repo[index]; }

    int getNumOfAnswers(int id);
    void sort(){
        std::sort(repo.begin(), repo.end(), [&](const Answer& q1, const Answer& q2){
            if(q1.getNumberOfVotes() > q2.getNumberOfVotes())
                return true;
            return false;
        });
    }
};


#endif //E916_916_LUCAS_SIPOS_1_ANSWERREPO_H
