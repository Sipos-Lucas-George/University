#pragma once

#include <string>

class Participant {
private:
    std::string name;
    int score = 0;

public:
    Participant(const std::string &name, int score);
    ~Participant() = default;

    const std::string &getName() const;

    void setName(const std::string &name);

    int getScore() const;

    void setScore(int score);

    std::string toString() { return this->name + "," + std::to_string(this->score) + "\n"; }
};
