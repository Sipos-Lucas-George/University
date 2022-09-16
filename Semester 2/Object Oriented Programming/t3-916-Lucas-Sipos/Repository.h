#pragma once
#include <vector>
#include "Task.h"

class Repository {
private:
    std::vector<Task> repository;

public:
    Repository();
    ~Repository() = default;

    void add(const Task& task);
    std::vector<Task> getAll();
    void sort();

    void readFromFile();
};
