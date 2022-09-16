//
// Created by lukyl on 12/06/2022.
//

#ifndef E916_916_LUCAS_SIPOS_1_ANSWER_H
#define E916_916_LUCAS_SIPOS_1_ANSWER_H


#include <string>

class Answer {
private:
    int id;
    int qID;
    std::string nameWhoAsked;
    std::string text;
    int numberOfVotes;
public:
    Answer() = default;
    Answer(int id, int qId, const std::string &nameWhoAsked, const std::string &text, int numberOfVotes);
    ~Answer() = default;

    int getId() const;

    void setId(int id);

    int getQid() const;

    void setQid(int qId);

    const std::string &getNameWhoAsked() const;

    void setNameWhoAsked(const std::string &nameWhoAsked);

    const std::string &getText() const;

    void setText(const std::string &text);

    int getNumberOfVotes() const;

    void setNumberOfVotes(int numberOfVotes);

    friend std::istream& operator>>(std::istream& is, Answer& question);
};


#endif //E916_916_LUCAS_SIPOS_1_ANSWER_H
