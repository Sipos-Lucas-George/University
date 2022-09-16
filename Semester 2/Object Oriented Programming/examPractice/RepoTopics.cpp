#include <fstream>
#include "RepoTopics.h"

void RepoTopics::readFile() {
    std::ifstream file("inputT.txt");
    if(!file.is_open())
        return;
    Topics topics;
    while (file >> topics)
        if (topics.getTopic() != "-1")
            this->repo.push_back(topics);
    file.close();

}

void RepoTopics::writeFile() {
    std::ofstream file("inputT.txt");
    if(!file.is_open())
        return;
    for(const auto& i : this->repo){
        std::string str;
        for (int x = 0; x < i.getList().size(); ++x)
            if (x == i.getList().size() - 1)
                str += i.getList()[x].getName();
            else
                str += i.getList()[x].getName() + ",";
        file << i.getTopic() + "\n";
    }
}
