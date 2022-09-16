#pragma once
#include <iostream>
#include <vector>
#include "../Domain/Player.h"
#include "DynamicVector.h"

class Repository {
private:
    DynamicVector<Player> dynamicVector;

public:
    Repository();
    ~Repository();

    void addPlayer(Player& player);
    int removePlayer(const std::string& name);

   DynamicVector<Player> getPlayers() { return this->dynamicVector; }
};
