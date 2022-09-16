//
// Created by lukyl on 12/06/2022.
//

#ifndef E916_916_LUCAS_SIPOS_1_USERREPO_H
#define E916_916_LUCAS_SIPOS_1_USERREPO_H
#include "User.h"
#include "Observer.h"
#include <algorithm>
#include <vector>

class UserRepo : public Subject{
private:
    std::vector<User> repo;

public:
    UserRepo() { this->readFile(); }
    ~UserRepo() = default;
    void addUser(const User& t) { this->repo.push_back(t); this->notify(); }
    void readFile();
    void writeFile();

    std::vector<User> getAll() { return this->repo; }
    User& operator[](int index) { return this->repo[index]; }
};


#endif //E916_916_LUCAS_SIPOS_1_USERREPO_H
