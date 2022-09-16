//
// Created by lukyl on 11/06/2022.
//

#ifndef EXAMPRACTICE3_OBSERVER_H
#define EXAMPRACTICE3_OBSERVER_H


#include <vector>

class Observer {
public:
    virtual void update() = 0;
};

class Subject {
private:
    std::vector<Observer*> list;
public:
    void addObserver(Observer* o) { this->list.push_back(o); }
    void notify();
};


#endif //EXAMPRACTICE3_OBSERVER_H
