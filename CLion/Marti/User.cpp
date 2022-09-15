#include "User.h"
#include <fstream>
#include <vector>

const std::string &User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    User::name = name;
}

User::User(const std::string &name) : name(name) {}

std::istream &operator>>(std::istream &is, User &user) {
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
            user.name = out[0];
        }
        else
            user.name = "-1";
    }
    return is;
}
