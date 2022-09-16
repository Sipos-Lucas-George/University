#pragma once

#include <vector>

class Observer {
public:
    virtual void update() = 0;
};

class Subject {
private:
    std::vector<Observer*> vector;

public:
    void addObserver(Observer* o) { vector.push_back(o); }
    void deleteObserver(Observer* o);
    void notify();
};
