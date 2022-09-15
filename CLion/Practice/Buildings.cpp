#include "Buildings.h"

Buildings::Buildings(std::string address, int year) {
    this->address = std::move(address);
    this->constructionYear = year;
}
