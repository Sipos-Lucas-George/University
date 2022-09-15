#pragma once
#include <vector>
#include <algorithm>
#include "Posts.h"
#include "Observer.h"

class RepoPosts : public Subject{
private:
    std::vector<Posts> repo;

public:
    RepoPosts() { this->readFile(); }
    ~RepoPosts() = default;

    void sort(){
        std::sort(repo.begin(), repo.end(), [&](const Posts& p1, const Posts& p2){
            if(p1.getTimestamp().compare(p2.getTimestamp()) < 0)
                return true;
            return false;
        });
    }

    void addPost(const Posts& p) { this->repo.push_back(p); this->sort(); this->writeFile(); this->notify(); }

    std::vector<Posts> getAll() { return repo; }

    void readFile();
    void writeFile();

};
