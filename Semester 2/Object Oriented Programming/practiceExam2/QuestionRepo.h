#pragma once

#include <vector>
#include "Question.h"
#include "Observer.h"

class QuestionRepo : public Subject{
private:
    std::vector<Question> repo;

public:
    QuestionRepo();
    ~QuestionRepo() = default;
    void addQuestion(const Question& question) { repo.push_back(question); this->notify(); this->writeFile(); }
    std::vector<Question> getAll() { return this->repo; }

    void readFile();
    void writeFile();
};