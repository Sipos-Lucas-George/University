#pragma once
#include <utility>

#include "../Service/Service.h"

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

    int addMovieService();
    int deleteMovieService();
    int updateMovieService();
    void listAllMovies();

    void watchStart();
    int userDelete();
    void printWatchList();

    static bool verifyMovie(const std::string& genre, const std::string& year, const std::string& likes);
    static bool verifyPositionType(const std::string& position);

    void initialization();
};
