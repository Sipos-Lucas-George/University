#pragma once

#include <string>

class User {
private:
    std::string name;

public:
    User(const std::string &name);
    ~User() = default;
    User() = default;

    const std::string &getName() const;

    void setName(const std::string &name);

    friend std::istream& operator>>(std::istream& is, User& user);
};
