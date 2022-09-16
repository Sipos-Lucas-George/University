//
// Created by lukyl on 12/06/2022.
//

#include "Question.h"

int Question::getId() const {
    return id;
}

void Question::setId(int id) {
    Question::id = id;
}

const std::string &Question::getText() const {
    return text;
}

void Question::setText(const std::string &text) {
    Question::text = text;
}

const std::string &Question::getName() const {
    return name;
}

void Question::setName(const std::string &name) {
    Question::name = name;
}

Question::Question(int id, const std::string &text, const std::string &name) : id(id), text(text), name(name) {}

std::istream &operator>>(std::istream &is, Question &question) {
    if (is.eof())
        is.setstate(std::ios_base::failbit);
    else {
        std::string string;
        std::vector<std::string> out;
        getline(is, string);
        if (!string.empty()) {
            size_t start;
            size_t end = 0;
            while ((start = string.find_first_not_of(',', end)) != std::string::npos) {
                end = string.find(',', start);
                out.push_back(string.substr(start, end - start));
            }
            question.id = stoi(out[0]);
            question.text = out[1];
            question.name = out[2];
        }
        else
            question.id = -1;
    }
    return is;
}
