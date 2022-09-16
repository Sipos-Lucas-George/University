#include "WatchList.h"

WatchList::~WatchList() = default;

int WatchList::addMovie(const Movie& movie) {
    if (this->search(movie.getTitle(), movie.getGenre(), movie.getYear()))
        return 0;
    this->movies.push_back(movie);
    return 1;
}

int WatchList::deleteMovieByPos(int position) {
    this->movies.erase(this->movies.begin()+position);
    return 1;
}

void WatchList::deleteMovie(Movie movie) {
    int pos, iteratorPosition = -1;
    std::for_each(this->movies.begin(), this->movies.end(), [&](const Movie& m) { ++iteratorPosition; if (m.getTitle() == movie.getTitle() && m.getGenre() == movie.getGenre() && m.getYear() == movie.getYear()) pos = iteratorPosition; });
    this->deleteMovieByPos(pos);
}

void WatchList::play() {
    this->movies[this->current].playTrailer();
}

void WatchList::playMovie(int pos) {
    this->movies[pos].playTrailer();
}

void WatchList::next() {
    if (this->current + 1 == this->movies.size())
    {
        this->current = 0;
        return;
    }
    this->current++;
}

Movie& WatchList::getCurrentMovie() {
    return this->movies[current];
}

bool WatchList::search(const std::string& title, const std::string& genre, int year) {
    bool returnValue = false;
    std::for_each(this->movies.begin(), this->movies.end(), [=, &returnValue](const Movie& movie) {
        if (movie.getTitle() == title && movie.getGenre() == genre && movie.getYear() == year) returnValue = true;});
    return returnValue;
}

//Movie& WatchList::operator[](int index) {
//    return this->movies[index];
//}

void WatchList::setMovies(const std::vector<Movie>& newMovies) {
    this->movies = newMovies;
}
