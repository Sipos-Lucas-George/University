#include <iostream>
#include "UI.h"

void UI::start() {
    menu();

    while(true){
        std::string command;
        std::cout << "Command: ";
        std::getline(std::cin, command);
        if (command == "exit")
            return;
        if (command == "menu")
            menu();
        if (command == "1"){
            this->addBuilding();
        }
        if (command == "2"){
            this->getAllBuildings();
        }
        if (command == "3"){
            this->getAllToBeRestored();
        }
        if (command == "4"){
            this->getAllToBeDemolished();
        }
        if (command == "5"){
            std::cout<<"Needs to be implemented!\n";
        }
    }
}

void UI::menu() {
    std::cout << "1 - add building\n";
    std::cout << "2 - get all\n";
    std::cout << "3 - get all to be restored\n";
    std::cout << "4 - get all to be demolished\n";
    std::cout << "5 - write to file\n";
}

void UI::addBuilding() {
    std::cout << "Type (house/block): ";
    std::string type, address, year;
    std::getline(std::cin, type);
    std::cout << "Address: ";
    std::getline(std::cin, address);
    std::cout << "Year: ";
    std::getline(std::cin, year);
    if (type == "house"){
        bool isHistorical;
        while(true){
            std::cout << "Historical (yes/no)?\n";
            std::string historical;
            std::getline(std::cin, historical);
            if (historical == "yes"){
                isHistorical = true;
                break;
            }
            if (historical == "no"){
                isHistorical = false;
                break;
            }
        }
        try{
            Buildings* building;
            auto house = new House{ address, stoi(year), isHistorical };
            building=house;
            this->service.addBuilding(building);
        }
        catch (std::invalid_argument& e){
            std::cout << "ERROR\n";
        }
    }
    else if (type == "block"){
        std::string total, occupied;
        std::cout << "Total apartments: ";
        std::getline(std::cin, total);
        std::cout << "Occupied apartments: ";
        std::getline(std::cin, occupied);
        try{
            Buildings* building = new Block{address, stoi(year), stoi(total), stoi(occupied)};
            this->service.addBuilding(building);
        }
        catch (std::invalid_argument& e){
            std::cout << "ERROR\n";
        }
    }
    else
        return;
}

void UI::getAllBuildings() {
    std::vector<Buildings*> vector = this->service.getAllBuildings();
    for (auto building : vector){
        std::cout << building->toString();
    }
}

void UI::getAllToBeRestored() {
    std::vector<Buildings *> vector = this->service.getAllToBeRestored();
    for (auto building: vector) {
        std::cout << building->toString();
    }
}

void UI::getAllToBeDemolished() {
    std::vector<Buildings*> vector = this->service.getAllToBeDemolished();
    for (auto building : vector){
        std::cout << building->toString();
    }
}
