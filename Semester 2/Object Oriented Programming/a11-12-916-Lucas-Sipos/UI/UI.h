#pragma once
#include <utility>
#include "../Service/Service.h"
#include "../ExceptionsValidators/Exceptions.h"
#include "../ExceptionsValidators/Validator.h"

class UI{
private:
    Service service;

public:
    explicit UI(Service& service);
    ~UI();

    void start();
    void runAdminMode();
    void runUserMode();

    static void printStartMenu();
    static void printAdminMenu();
    static void printUserMenu();
    static void printWatchMenu();

    void addMovieService();
    void deleteMovieService();
    void updateMovieService();
    void listAllMovies();

    void watchStart();
    int userDelete();
    void printWatchList();

    static bool verifyPositionType(const std::string& position);

//    void initialization();
};
