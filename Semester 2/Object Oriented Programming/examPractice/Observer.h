//
// Created by lukyl on 06/07/2022.
//

#ifndef MARTI_OBSERVER_H
#define MARTI_OBSERVER_H

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
    void notify(){
        for (auto o : list)
            o->update();
    }
};


#endif //MARTI_OBSERVER_H
