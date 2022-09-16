//
// Created by lukyl on 12/06/2022.
//

#include "AnswerRepo.h"
#include <fstream>
#include <cstring>

void AnswerRepo::readFile() {
    std::ifstream file("inputA.txt");
    if(!file.is_open())
        return;
    Answer answer;
    while (file >> answer)
        if (answer.getId() != -1)
            this->repo.push_back(answer);
    file.close();
}

int AnswerRepo::getNumOfAnswers(int id) {
    int sum = 0;
    for (const auto& i : this->repo){
        if (id == i.getQid())
            ++sum;
    }
    return sum;
}

void AnswerRepo::writeFile() {
    std::ofstream file("inputA.txt");
    if(!file.is_open())
        return;
    for(const auto& i : this->repo)
        file << std::to_string(i.getId()) + "," + std::to_string(i.getQid()) + "," + i.getNameWhoAsked()+ "," + i.getText() + "," + std::to_string(i.getNumberOfVotes()) + "\n";
}

int AnswerRepo::getHighestID() {
    int id = 0;
    for(const auto& i : this->repo){
        if(id < i.getId())
            id = i.getId();
    }
    return id;
}
