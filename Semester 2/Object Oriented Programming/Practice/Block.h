#pragma once
#include "Buildings.h"

class Block : public Buildings{
private:
    int totalApartaments;
    int ocuppiedApartments;

public:
    Block(std::string address, int year, int totalApar, int occApar);
    ~Block() = default;

    bool mustBeRestored() override;

    bool canBeDemolished() override;

    std::string toString() override;
};
