//
// Created by lukyl on 12/06/2022.
//

#include "QuestionRepo.h"
#include <fstream>
#include <cstring>

void QuestionRepo::readFile() {
    std::ifstream file("inputQ.txt");
    if(!file.is_open())
        return;
    Question question;
    while (file >> question)
        if (question.getId() != -1)
            this->repo.push_back(question);
    file.close();
}

int QuestionRepo::getHighestID() {
    int id = 0;
    for(const auto& i : this->repo){
        if(id < i.getId())
            id = i.getId();
    }
    return id;
}

void QuestionRepo::writeFile() {
    std::ofstream file("inputQ.txt");
    if(!file.is_open())
        return;
    for(const auto& i : this->repo)
        file << std::to_string(i.getId()) + "," + i.getText() + "," + i.getName() + "\n";
}
