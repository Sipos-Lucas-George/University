#include "WatchList.h"

WatchList::WatchList() = default;

WatchList::~WatchList() = default;

int WatchList::addMovie(const Movie& movie) {
    if (binarySearchMovie(movie.getTitle(), movie.getGenre(), movie.getYear()))
        return 0;
    this->movies.addItem(movie);
    return 1;
}

int WatchList::deleteMovieByPos(int position) {
    this->movies.deleteItem(position);
    return 1;
}

void WatchList::deleteMovie(Movie& movie) {
    for (int i = 0; i < this->movies.getSize(); i++)
        if (this->movies[i].getGenre() == movie.getGenre() && this->movies[i].getTitle() == movie.getTitle() && this->movies[i].getYear() == movie.getYear())
            this->movies.deleteItem(i);
}

void WatchList::play() {
    this->movies[this->current].playTrailer();
}

void WatchList::next() {
    if (this->current + 1 == this->movies.getSize())
    {
        this->current = 0;
        return;
    }
    this->current++;
}

Movie& WatchList::getCurrentMovie() {
    return this->movies[current];
}

bool WatchList::binarySearchMovie(const std::string& title, const std::string& genre, int year) {
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

bool WatchList::compareIfSameMovie(const Movie& movie, const std::string& title, const std::string& genre, int year) {
    if (movie.getTitle() == title && movie.getGenre() == genre && movie.getYear() == year)
        return true;
    return false;
}

Movie& WatchList::operator[](int index) {
    return this->movies[index];
}
