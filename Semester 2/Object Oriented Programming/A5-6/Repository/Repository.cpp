#include "Repository.h"

Repository::Repository() = default;

Repository::~Repository() = default;

int Repository::addMovie(const Movie& movie) {
    if (binarySearchMovie(movie.getTitle(), movie.getGenre(), movie.getYear()))
        return 0;
    this->movies.addItem(movie);
    return 1;
}

int Repository::deleteMovie(int position) {
    this->movies.deleteItem(position);
    return 1;
}

int Repository::updateMovie(int position, const Movie& movie) {
    if (binarySearchMovie(movie.getTitle(), movie.getGenre(), movie.getYear()))
        return 0;
    this->movies.updateItem(position, movie);
    return 1;
}

bool Repository::binarySearchMovie(const std::string& title, const std::string& genre, int year) {
    int left = 0, right = this->movies.getSize();
    while (left <= right){
        int mid = (left + right) / 2;
        if (compareIfSameMovie(this->movies[mid], title, genre, year))
            return true;
        else if (this->movies[mid].getTitle().compare(title) < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

bool Repository::compareIfSameMovie(const Movie& movie, const std::string& title, const std::string& genre, int year) {
    if (movie.getTitle() == title && movie.getGenre() == genre && movie.getYear() == year)
        return true;
    return false;
}

int Repository::findPositionOfMovie(const Movie &movie) {
    for (int i = 0; i < this->movies.getSize(); i++)
        if (this->movies[i].getGenre() == movie.getGenre() && this->movies[i].getTitle() == movie.getTitle() && this->movies[i].getYear() == movie.getYear())
            return i;
    return -1;
}

Movie& Repository::operator[](int index) {
    return this->movies[index];
}
