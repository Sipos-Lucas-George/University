//
// Created by lukyl on 04/04/2022.
//

#include "Player.h"

#include <utility>

Player::Player() {
    this->name = "";
    this->nationality = "";
    this->team = "";
    this->goals = 0;
}

Player::Player(std::string name, std::string nat, std::string team, int goals) {
    this->name = std::move(name);
    this->nationality = std::move(nat);
    this->team = std::move(team);
    this->goals = goals;
}

Player::~Player() = default;

std::string Player::toString() {
    std::string str;
    str = this->name + " | " + this->nationality + " | " + this->team + " | " + std::to_string(this->goals);
    return str;
}
