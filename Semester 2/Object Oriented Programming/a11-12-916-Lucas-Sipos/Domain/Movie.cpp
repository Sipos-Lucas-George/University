#include "Movie.h"

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

std::istream& operator>>(std::istream& is, Movie& movie) {
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
            movie.title = out[0];
            movie.genre = out[1];
            movie.year = stoi(out[2]);
            movie.likes = stoi(out[3]);
            movie.trailer = out[4];
        }
        else
            movie.likes = -1;
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Movie& movie)
{
    os << movie.title << "," << movie.genre << "," << movie.year << "," << movie.likes << "," << movie.trailer << "\n";
    return os;
}
