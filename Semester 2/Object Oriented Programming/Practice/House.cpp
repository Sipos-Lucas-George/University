#include "House.h"

#include <utility>

House::House(std::string address, int year, bool isHistorical) : Buildings{std::move(address), year}{
    this->isHistorical = isHistorical;
}

bool House::mustBeRestored() {
    return this->constructionYear > 100;
}

bool House::canBeDemolished() {
    return !this->isHistorical;
}

std::string House::toString() {
    std::string string;
    string = this->address + " " + std::to_string(this->constructionYear) + " ";
    if (this->isHistorical)
        string += "Historical\n";
    else
        string += "Normal\n";
    return string;
}
