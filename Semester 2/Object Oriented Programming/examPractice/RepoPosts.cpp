#include <fstream>
#include "RepoPosts.h"

void RepoPosts::readFile() {
    std::ifstream file("inputP.txt");
    if(!file.is_open())
        return;
    Posts posts;
    while (file >> posts)
        if (posts.getId() != -1)
            this->repo.push_back(posts);
    file.close();
}

void RepoPosts::writeFile() {
    std::ofstream file("inputP.txt");
    if(!file.is_open())
        return;
    for(const auto& i : this->repo)
        file << std::to_string(i.getId()) + "," + i.getText() + "," + i.getTimestamp() + "," + i.getUser().getName() + "\n";
}


