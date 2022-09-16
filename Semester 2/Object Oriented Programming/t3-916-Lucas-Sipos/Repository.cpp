#include <fstream>
#include "Repository.h"
#include <cstring>

Repository::Repository() {
    this->readFromFile();
}

void Repository::add(const Task &task) {
    this->repository.push_back(task);
}

std::vector<Task> Repository::getAll() {
    return this->repository;
}

void Repository::sort(){
    int ok = 1;
    while(ok == 1){
        ok = 0;
        for(int i = 0; i < this->repository.size() - 1; ++i){
            if(this->repository[i].getPri() > this->repository[i+1].getPri()){
                auto obj = this->repository[i];
                this->repository[i] = this->repository[i+1];
                this->repository[i+1] = obj;
                ok = 1;
            }
            else if(this->repository[i].getPri() == this->repository[i+1].getPri()){
                if (this->repository[i].getDur() < this->repository[i+1].getDur()){
                    auto obj = this->repository[i];
                    this->repository[i] = this->repository[i+1];
                    this->repository[i+1] = obj;
                    ok = 1;
                }
            }
        }
    }
}

void Repository::readFromFile() {
    std::ifstream file("input.txt");
    char task[500];
    if (!file.is_open())
        return;
    while (true){
        std::vector<std::string> vector;
        file >> task;
        char* p = strtok(task, ",");
        while(p){
            vector.push_back((std::string)(p));
            p = strtok(nullptr, ",");
        }
        if(vector.size() != 3)
            break;
        this->add(Task(vector[0], stoi(vector[1]), stoi(vector[2])));
    }
    file.close();
}
