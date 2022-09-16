#pragma once
#include <utility>
#include <vector>
#include <string>
#include "Buildings.h"
#include "House.h"
#include "Block.h"

class Service {
private:
    std::vector<Buildings*> buildings;

public:
    Service() = default;
    ~Service() = default;

    void addBuilding(Buildings* building);

    std::vector<Buildings*> getAllBuildings();

    std::vector<Buildings*> getAllToBeRestored();

    std::vector<Buildings*> getAllToBeDemolished();

    void writeToFile(const std::string& filename, const std::vector<Buildings*>& b);
};
