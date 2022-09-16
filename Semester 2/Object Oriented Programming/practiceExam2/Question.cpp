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

const std::string &Question::getAnswer() const {
    return answer;
}

void Question::setAnswer(const std::string &answer) {
    Question::answer = answer;
}

int Question::getScore() const {
    return score;
}

void Question::setScore(int score) {
    Question::score = score;
}

Question::Question(int id, const std::string &text, const std::string &answer, int score) : id(id), text(text),
                                                                                            answer(answer),
                                                                                            score(score) {}
