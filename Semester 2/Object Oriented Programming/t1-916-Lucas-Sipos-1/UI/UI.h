#pragma once
#include "../Service/Service.h"

class UI {
private:
    Service service;
public:
    explicit UI(Service& service);
    ~UI();

    void start();
    void printMenu();

    int addPlayerUI();
    int removePlayerUI();
    void listAllPlayers();
    void listAllPlayerByNat();
};
