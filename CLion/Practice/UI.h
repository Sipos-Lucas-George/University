#pragma once
#include "Service.h"
#include "Buildings.h"
#include "House.h"
#include "Block.h"

class UI {
private:
    Service service;

public:
    explicit UI(const Service& service) { this->service = service; }
    ~UI() = default;

    void start();

    void addBuilding();

    void getAllBuildings();

    void getAllToBeRestored();

    void getAllToBeDemolished();

//    virtual void writeToFile(std::string filename, std::vector<Buildings*>) = 0;
    static void menu();
};
