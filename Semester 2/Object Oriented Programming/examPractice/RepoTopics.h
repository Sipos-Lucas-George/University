#pragma once
#include "Topics.h"
#include <vector>
#include <algorithm>
#include "Observer.h"

class RepoTopics : public Subject {
private:
    std::vector<Topics> repo;

public:
    RepoTopics() { this->readFile(); }
    ~RepoTopics() = default;

    void addTopic(const Topics& t) { this->repo.push_back(t); this->writeFile(); this->notify(); }

    std::vector<Topics> getAll() { return repo; }
    Topics& operator[](int index) { return this->repo[index]; }

    void readFile();
    void writeFile();
};
