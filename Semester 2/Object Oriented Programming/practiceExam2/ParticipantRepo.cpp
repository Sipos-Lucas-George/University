#include <fstream>
#include <cstring>
#include "ParticipantRepo.h"

ParticipantRepo::ParticipantRepo() {
    this->readFile();
}

void ParticipantRepo::readFile() {
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
        if(vector.size() != 2)
            break;
        this->addParticipant(Participant(vector[0], stoi(vector[1])));
    }
}

void ParticipantRepo::writeFile() {
    std::ofstream file("input2.txt");
    if(!file.is_open())
        return;
    for (auto p : this->repo)
        file << p.toString();
}
