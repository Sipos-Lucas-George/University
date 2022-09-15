#pragma once

#include <vector>
#include "User.h"
#include "Topics.h"

class Posts {
private:
    int id;
    std::string text;
    std::string timestamp;
    User user;

public:
    Posts(int id, const std::string &text, std::string timestamp, const User &user);
    ~Posts() = default;
    Posts() = default;

    bool findTopic(std::vector<Topics> t, std::string name){
        for (auto i : t){
            if(this->text.find(i.getTopic()) != std::string::npos && i.findName(name))
                return true;
        }
        return false;
    }

    int getId() const;

    const std::string &getText() const;

    void setText(const std::string &text);

    const User &getUser() const;

    void setUser(const User &user);

    std::string getTimestamp() const;

    std::string currentDateTime() {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
        return buf;
    }

    friend std::istream& operator>>(std::istream& is, Posts& posts);
};
