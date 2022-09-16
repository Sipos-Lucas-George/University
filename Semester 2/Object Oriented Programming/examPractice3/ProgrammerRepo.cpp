//
// Created by lukyl on 11/06/2022.
//
#include "ProgrammerRepo.h"
#include <cstring>
#include <fstream>

void ProgrammerRepo::readFile() {
    std::ifstream file("input1.txt");
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
        if(vector.size() != 2)
            break;
        this->addProgrammer(Programmer(vector[0], stoi(vector[1])));
    }
    file.close();
}
