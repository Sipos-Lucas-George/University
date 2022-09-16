#include "Task.h"

#include <utility>

Task::Task(std::string des, int dur, int pri) {
    this->description = std::move(des);
    this->duration = dur;
    this->priority = pri;
}
