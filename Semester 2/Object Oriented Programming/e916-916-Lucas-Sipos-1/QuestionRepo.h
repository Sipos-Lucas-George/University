//
// Created by lukyl on 12/06/2022.
//

#ifndef E916_916_LUCAS_SIPOS_1_QUESTIONREPO_H
#define E916_916_LUCAS_SIPOS_1_QUESTIONREPO_H
#include "Question.h"
#include "Observer.h"
#include <algorithm>
#include <vector>
#include "AnswerRepo.h"

class QuestionRepo : public Subject{
private:
    std::vector<Question> repo;
    AnswerRepo aRepo;

public:
    QuestionRepo(AnswerRepo aRepo) { this->readFile(); this->aRepo = aRepo; }
    ~QuestionRepo() = default;
    void addQuestion(const Question& t) { this->repo.push_back(t); this->sort(); this->writeFile(); this->notify(); }
    void readFile();
    void writeFile();

    int getHighestID();

    std::vector<Question> getAll() { return this->repo; }
    Question& operator[](int index) { return this->repo[index]; }
    void sort(){
        std::sort(repo.begin(), repo.end(), [&](const Question& q1, const Question& q2){
            if(this->aRepo.getNumOfAnswers(q1.getId()) > this->aRepo.getNumOfAnswers(q2.getId()))
                return true;
            return false;
        });
    }
};


#endif //E916_916_LUCAS_SIPOS_1_QUESTIONREPO_H
