#include "Topics.h"
#include <fstream>
const std::string &Topics::getTopic() const {
    return topic;
}

void Topics::setTopic(const std::string &topic) {
    Topics::topic = topic;
}

const std::vector<User> &Topics::getList() const {
    return list;
}

Topics::Topics(const std::string &topic, const std::vector<User> &list) : topic(topic), list(list) {}

std::istream &operator>>(std::istream &is, Topics &topics) {
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
            topics.topic = out[0];
            for(int i = 1; i < out.size(); ++i)
                topics.list.emplace_back(out[i]);
        }
        else
            topics.topic = "-1";
    }
    return is;
}
