#pragma once
#include <iostream>

class Player {
private:
    std::string name;
    std::string nationality;
    std::string team;
    int goals;

public:
    Player();
    Player(std::string, std::string, std::string, int);
    ~Player();

    std::string getName() { return this->name; }
    std::string getNat() { return this->nationality; }
    std::string getTeam() { return this->team; }
    int getGoals() const { return this->goals; }

    std::string toString();
};

