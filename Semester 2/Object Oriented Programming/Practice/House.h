#pragma once
#include "Buildings.h"

class House : public Buildings{
private:
    bool isHistorical;

public:
    explicit House(std::string address, int year, bool isHistorical);
    ~House() = default;

    bool mustBeRestored() override;

    bool canBeDemolished() override;

    std::string toString() override;
};
