//
// Created by lukyl on 11/06/2022.
//

#ifndef EXAMPRACTICE3_TASKREPO_H
#define EXAMPRACTICE3_TASKREPO_H
#include <vector>
#include <algorithm>
#include "Task.h"
#include "Observer.h"

class TaskRepo : public Subject{
private:
    std::vector<Task> repo;

public:
    TaskRepo() { this->readFile(); }
    ~TaskRepo() = default;
    void addTask(const Task& t) { this->repo.push_back(t); this->sort(); this->notify(); }
    void deleteTask(int index) { this->repo.erase(this->repo.begin() + index); this->notify(); }
    void sort();
    void readFile();
    void writeFile();

    std::vector<Task> getAll() { return this->repo; }
    Task& operator[](int index) { return this->repo[index]; }
};


#endif //EXAMPRACTICE3_TASKREPO_H
