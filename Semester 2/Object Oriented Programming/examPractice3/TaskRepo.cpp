//
// Created by lukyl on 11/06/2022.
//

#include "TaskRepo.h"
#include <fstream>
#include <cstring>

void TaskRepo::readFile() {
    std::ifstream file("input2.txt");
    if(!file.is_open())
        return;
    char info[500];
    while(true){
        std::vector<std::string> vector;
        file >> info;
        char *p = strtok(info, ",");
        while(p){
            vector.emplace_back((std::string)p);
            p = strtok(nullptr, ",");
        }
        if(vector.size() != 3)
            break;
        this->addTask(Task(vector[0], vector[1], stoi(vector[2])));
    }
    file.close();
}

void TaskRepo::writeFile() {
    std::ofstream file("input2.txt");
    if(!file.is_open())
        return;
    for (const auto& t : repo){
        file << t.getDesc() + "," + t.getStatus() + "," + std::to_string(t.getId()) + "\n";
    }
    file.close();
}

void TaskRepo::sort() {
    std::sort(this->repo.begin(), this->repo.end(), [&](const Task& t1, const Task& t2) {
        if(t1.getStatus() < t2.getStatus())
            return true;
        return false;
    });
}
