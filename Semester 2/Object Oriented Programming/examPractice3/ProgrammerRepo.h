//
// Created by lukyl on 11/06/2022.
//

#ifndef EXAMPRACTICE3_PROGRAMMERREPO_H
#define EXAMPRACTICE3_PROGRAMMERREPO_H

#include <vector>
#include "Programmer.h"

class ProgrammerRepo {
private:
    std::vector<Programmer> repo;

public:
    ProgrammerRepo() { this->readFile(); }
    ~ProgrammerRepo() = default;
    void addProgrammer(const Programmer& p) { this->repo.push_back(p); }
    std::string getProgrammer(int id){
        for(auto& p : this->repo)
            if(p.getId() == id)
                return p.getName();
        return "";
    }
    void readFile();
    std::vector<Programmer> getAll() { return this->repo; }
};


#endif //EXAMPRACTICE3_PROGRAMMERREPO_H
