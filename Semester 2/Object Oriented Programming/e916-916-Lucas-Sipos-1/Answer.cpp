//
// Created by lukyl on 12/06/2022.
//

#include <vector>
#include "Answer.h"
#include <fstream>

int Answer::getId() const {
    return id;
}

void Answer::setId(int id) {
    Answer::id = id;
}

int Answer::getQid() const {
    return qID;
}

void Answer::setQid(int qId) {
    qID = qId;
}

const std::string &Answer::getNameWhoAsked() const {
    return nameWhoAsked;
}

void Answer::setNameWhoAsked(const std::string &nameWhoAsked) {
    Answer::nameWhoAsked = nameWhoAsked;
}

const std::string &Answer::getText() const {
    return text;
}

void Answer::setText(const std::string &text) {
    Answer::text = text;
}

int Answer::getNumberOfVotes() const {
    return numberOfVotes;
}

void Answer::setNumberOfVotes(int numberOfVotes) {
    Answer::numberOfVotes = numberOfVotes;
}

Answer::Answer(int id, int qId, const std::string &nameWhoAsked, const std::string &text, int numberOfVotes) : id(id),
                                                                                                               qID(qId),
                                                                                                               nameWhoAsked(
                                                                                                                       nameWhoAsked),
                                                                                                               text(text),
                                                                                                               numberOfVotes(
                                                                                                                       numberOfVotes) {}

std::istream &operator>>(std::istream &is, Answer &answer) {
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
            answer.id = stoi(out[0]);
            answer.qID = stoi(out[1]);
            answer.nameWhoAsked = out[2];
            answer.text = out[3];
            answer.numberOfVotes = stoi(out[4]);
        }
        else
            answer.id = -1;
    }
    return is;
}
