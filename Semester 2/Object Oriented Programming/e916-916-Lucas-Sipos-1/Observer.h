//
// Created by lukyl on 12/06/2022.
//

#ifndef E916_916_LUCAS_SIPOS_1_OBSERVER_H
#define E916_916_LUCAS_SIPOS_1_OBSERVER_H


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


#endif //E916_916_LUCAS_SIPOS_1_OBSERVER_H
