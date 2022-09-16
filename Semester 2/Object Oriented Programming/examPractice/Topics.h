#pragma once
#include "User.h"
#include <string>
#include <vector>

class Topics {
private:
    std::string topic;
    std::vector<User> list;

public:
    Topics(const std::string &topic, const std::vector<User> &list);
    ~Topics() = default;
    Topics() = default;

    bool findName(std::string name){
        for(const auto& a : list){
            if (a.getName() == name)
                return true;
        }
        return false;
    }

    const std::string &getTopic() const;

    void setTopic(const std::string &topic);

    const std::vector<User> &getList() const;

    void addList(const User& user) { list.push_back(user); }

    friend std::istream& operator>>(std::istream& is, Topics& topics);
};
