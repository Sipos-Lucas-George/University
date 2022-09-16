#pragma once
#include <iostream>

class Task {
private:
    std::string description;
    int duration;
    int priority;
public:
    Task(std::string des, int dur, int pri);
    ~Task() = default;

    std::string getDes() { return this->description; }
    int getDur() { return this->duration; }
    int getPri() { return this->priority; }
};

