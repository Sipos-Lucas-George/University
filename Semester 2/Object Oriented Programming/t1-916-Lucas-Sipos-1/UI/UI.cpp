#include "UI.h"

UI::UI(Service &service) : service(service){
    this->service = service;
}

UI::~UI() = default;

void UI::start() {
    while (true) {
        printMenu();
        std::string command;
        std::getline(std::cin, command);
        if (command == "exit")
            break;
        if (command == "add"){
            this->addPlayerUI();
        }
        else if (command == "remove"){
            this->removePlayerUI();
        }
        else if (command == "list"){
            this->listAllPlayers();
        }
        else if (command == "remove"){
            this->listAllPlayerByNat();
        }
        else
            std::cout << "Invalid command!\n";
    }

}

int UI::addPlayerUI() {
    std::string name, nat, team, goals;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter nat: ";
    std::getline(std::cin, nat);
    std::cout << "Enter team: ";
    std::getline(std::cin, team);
    std::cout << "Enter goals: ";
    std::cin >> goals

    int var = this->service.addPlayerService(Player(name, nat, team, goals))
}

int UI::removePlayerUI() {
    std::string name;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    this->service
}

void printMenu(){
    std::cout << "\nadd - add player\nremove - remove player\nlist - list all\nlistN - list all by nat\n";
}