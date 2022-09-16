//
// Created by lukyl on 12/06/2022.
//

#include "UserRepo.h"
#include <fstream>
#include <cstring>

void UserRepo::readFile() {
    std::ifstream file("inputU.txt");
    if(!file.is_open())
        return;
    User user;
    while (file >> user)
        if (user.getName() != "-1")
            this->repo.push_back(user);
    file.close();
}

void UserRepo::writeFile() {
    std::ofstream file("inputU.txt");
    if(!file.is_open())
        return;
    for(const auto& i : this->repo)
        file << i.getName() + "\n";
}
