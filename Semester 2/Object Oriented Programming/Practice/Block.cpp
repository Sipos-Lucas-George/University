#include "Block.h"

#include <utility>

Block::Block(std::string address, int year, int totalApar, int occApar) : Buildings{ std::move(address), year }{
    this->totalApartaments = totalApar;
    this->ocuppiedApartments = occApar;
}

bool Block::mustBeRestored() {
    if (this->constructionYear - 2022 > 40 && (float)this->ocuppiedApartments > (float)(0.8 * this->totalApartaments))
        return true;
    return false;
}

bool Block::canBeDemolished() {
    if ((float)this->ocuppiedApartments < (float)(0.05 * this->totalApartaments))
        return true;
    return false;
}

std::string Block::toString() {
    std::string string;
    string = this->address + " " + std::to_string(this->constructionYear) + " " + std::to_string(this->totalApartaments) + " " + std::to_string(this->ocuppiedApartments) + "\n";
    return string;
}
