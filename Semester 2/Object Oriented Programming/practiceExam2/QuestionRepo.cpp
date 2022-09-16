#include "QuestionRepo.h"
#include <fstream>
#include <cstring>

QuestionRepo::QuestionRepo() {
    this->readFile();
}

void QuestionRepo::readFile() {
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
        if(vector.size() != 4)
            break;
        this->addQuestion(Question(stoi(vector[0]), vector[1], vector[2], stoi(vector[3])));
    }
}

void QuestionRepo::writeFile() {
    std::ofstream file("input1.txt");
    if(!file.is_open())
        return;
    for (auto p : this->repo)
        file << p.toString();
}
