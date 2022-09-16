#pragma once
#include <string>

class Buildings {
protected:
    std::string address;
    int constructionYear;

public:
    Buildings(std::string address, int year);
    ~Buildings() = default;

    virtual bool mustBeRestored() = 0;

    virtual bool canBeDemolished() = 0;

    virtual std::string toString() = 0;
};
