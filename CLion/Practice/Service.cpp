#include <fstream>
#include <iostream>
#include "Service.h"

 void Service::addBuilding(Buildings* building) {
    this->buildings.push_back(building);
}

std::vector<Buildings *> Service::getAllBuildings() {
    return this->buildings;
}

std::vector<Buildings *> Service::getAllToBeRestored() {
    std::vector<Buildings*> vector;
    for (auto building : this->buildings)
        if (building->mustBeRestored())
            vector.push_back(building);
    return vector;
}

std::vector<Buildings *> Service::getAllToBeDemolished() {
    std::vector<Buildings*> vector;
    for (auto building : this->buildings)
        if (building->canBeDemolished())
            vector.push_back(building);
    return vector;
}

void Service::writeToFile(const std::string& filename, const std::vector<Buildings *>& b) {
    std::ofstream g(filename);
    if (!g.is_open()) {
        std::cerr << "Could not open file";
    }
    for (auto &building: b) {
        g << building->toString();
    }
    g.close();
}
