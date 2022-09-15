#include <fstream>
#include "RepoUsers.h"

void RepoUsers::readFile() {
    std::ifstream file("inputU.txt");
    if(!file.is_open())
        return;
    User user;
    while (file >> user)
        if (user.getName() != "-1")
            this->repo.push_back(user);
    file.close();
}

void RepoUsers::writeFile() {
    std::ofstream file("inputU.txt");
    if(!file.is_open())
        return;
    for(const auto& i : this->repo)
        file << i.getName() + "\n";
}
