#include "Posts.h"
#include <fstream>
#include <vector>

int Posts::getId() const {
    return id;
}

const std::string &Posts::getText() const {
    return text;
}

void Posts::setText(const std::string &text) {
    Posts::text = text;
}

const User &Posts::getUser() const {
    return user;
}

void Posts::setUser(const User &user) {
    Posts::user = user;
}

std::string Posts::getTimestamp() const {
    return timestamp;
}

Posts::Posts(int id, const std::string &text, std::string timestamp, const User &user) : id(id), text(text),
                                                                              user(user) {
    timestamp = this->currentDateTime();
}

std::istream &operator>>(std::istream &is, Posts &posts) {
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
            posts.id = stoi(out[0]);
            posts.text = out[1];
            posts.timestamp = out[2];
            posts.user = User(out[3]);
        }
        else
            posts.id = -1;
    }
    return is;
}

