#include "Movie.h"
#include <Windows.h>
#include <shellapi.h>
#include <utility>

Movie::Movie() {
    this->year = 0;
    this->likes = 0;
    this->ifLiked = 0;
}

Movie::~Movie() = default;

Movie::Movie(std::string title, std::string genre, int year, int likes, std::string trailer) {
    this->title = std::move(title);
    this->genre = std::move(genre);
    this->year = year;
    this->likes = likes;
    this->trailer = std::move(trailer);
    this->ifLiked = 0;
}

void Movie::incrementLikes() {
    if (this->ifLiked == 0) {
        this->ifLiked = 1;
        ++this->likes;
    }
}

void Movie::playTrailer() const {
    ShellExecuteA(nullptr, nullptr, "chrome.exe", this->getTrailer().c_str(), nullptr, SW_SHOWMAXIMIZED);
}

std::string Movie::toString() {
    std::string str;
    str = "\tTitle: " + this->title + " Genre: " + this->genre + " Year: " + std::to_string(this->year) + " Likes: " + std::to_string(this->likes) + "\n\tTrailer: " + this->trailer;
    return str;
}
