#include "Repository.h"

Repository::Repository() = default;

Repository::~Repository() = default;

void Repository::addPlayer(Player &player) {
    this->dynamicVector.add(player);
}

int Repository::removePlayer(const std::string& name) {
    for (int i = 0; i < this->dynamicVector.getSize(); ++i){
        if (this->dynamicVector[i].getName() == name){
            this->dynamicVector.remove(i);
            return 1;
        }
    }
    return 0;
}
