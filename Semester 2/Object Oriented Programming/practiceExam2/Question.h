#pragma once

#include <string>

class Question {
private:
    int id;
    std::string text;
    std::string answer;
    int score;

public:
    Question(int id, const std::string &text, const std::string &answer, int score);
    ~Question() = default;

    int getId() const;

    void setId(int id);

    const std::string &getText() const;

    void setText(const std::string &text);

    const std::string &getAnswer() const;

    void setAnswer(const std::string &answer);

    int getScore() const;

    void setScore(int score);

    std::string toString() { return std::to_string(this->id) + "," + this->text + "," + this->answer + "," + std::to_string(this->score) + "\n"; }
};
