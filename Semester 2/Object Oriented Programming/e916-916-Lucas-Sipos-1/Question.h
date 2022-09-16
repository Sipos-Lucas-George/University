//
// Created by lukyl on 12/06/2022.
//

#ifndef E916_916_LUCAS_SIPOS_1_QUESTION_H
#define E916_916_LUCAS_SIPOS_1_QUESTION_H


#include <string>
#include <vector>
#include <fstream>
class Question {
private:
    int id;
    std::string text;
    std::string name;

public:
    Question() = default;
    Question(int id, const std::string &text, const std::string &name);
    ~Question() = default;

    int getId() const;

    void setId(int id);

    const std::string &getText() const;

    void setText(const std::string &text);

    const std::string &getName() const;

    void setName(const std::string &name);

    friend std::istream& operator>>(std::istream& is, Question& question);
};


#endif //E916_916_LUCAS_SIPOS_1_QUESTION_H
