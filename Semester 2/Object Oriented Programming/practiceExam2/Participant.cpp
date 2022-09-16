//
// Created by lukyl on 10/06/2022.
//

#include "Participant.h"

Participant::Participant(const std::string &name, int score) : name(name), score(score) {}

const std::string &Participant::getName() const {
    return name;
}

void Participant::setName(const std::string &name) {
    Participant::name = name;
}

int Participant::getScore() const {
    return score;
}

void Participant::setScore(int score) {
    Participant::score = score;
}
