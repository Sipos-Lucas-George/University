#pragma once
#include <vector>
#include "User.h"

class RepoUsers {
private:
    std::vector<User> repo;

public:
    RepoUsers() { this->readFile(); }
    ~RepoUsers() = default;

    std::vector<User> getAll() { return repo; }

    void readFile();
    void writeFile();
};
