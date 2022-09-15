//
// Created by lukyl on 11/06/2022.
//

#ifndef EXAMPRACTICE3_TASK_H
#define EXAMPRACTICE3_TASK_H


#include <string>

class Task {
    std::string desc;
    std::string status;
    int id;
public:
    Task(const std::string &desc, const std::string &status, int id);
    ~Task() = default;

    const std::string &getDesc() const;

    void setDesc(const std::string &desc);

    const std::string &getStatus() const;

    void setStatus(const std::string &status);

    int getId() const;

    void setId(int id);
};


#endif //EXAMPRACTICE3_TASK_H
