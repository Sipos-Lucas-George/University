//
// Created by lukyl on 11/06/2022.
//

#include "Task.h"

Task::Task(const std::string &desc, const std::string &status, int id) : desc(desc), status(status), id(id) {}

const std::string &Task::getDesc() const {
    return desc;
}

void Task::setDesc(const std::string &desc) {
    Task::desc = desc;
}

const std::string &Task::getStatus() const {
    return status;
}

void Task::setStatus(const std::string &status) {
    Task::status = status;
}

int Task::getId() const {
    return id;
}

void Task::setId(int id) {
    Task::id = id;
}
