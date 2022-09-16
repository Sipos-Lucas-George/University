//
// Created by lukyl on 12/06/2022.
//

#ifndef E916_916_LUCAS_SIPOS_1_USER_H
#define E916_916_LUCAS_SIPOS_1_USER_H


#include <string>
#include <utility>

class User {
private:
    std::string name;
public:
    User() = default;
    User(std::string name) { this->name = std::move(name); }
    ~User() = default;
    const std::string &getName() const;

    void setName(const std::string &name);

    friend std::istream& operator>>(std::istream& is, User& user);
};


#endif //E916_916_LUCAS_SIPOS_1_USER_H
