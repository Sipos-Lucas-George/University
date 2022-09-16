//
// Created by lukyl on 11/06/2022.
//

#ifndef EXAMPRACTICE3_PROGRAMMER_H
#define EXAMPRACTICE3_PROGRAMMER_H


#include <string>

class Programmer {
private:
    std::string name;
    int id;

public:
    Programmer(const std::string &name, int id);
    ~Programmer() = default;

    const std::string &getName() const;

    void setName(const std::string &name);

    int getId() const;

    void setId(int id);
};


#endif //EXAMPRACTICE3_PROGRAMMER_H
