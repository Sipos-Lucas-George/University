#include "Repository.h"

#include <utility>

Repository::Repository(std::string filename) {
    this->filename = std::move(filename);
    this->readFromFile();
}

Repository::~Repository() = default;

void Repository::addMovie(const Movie& movie) {
    if (this->search(movie.getTitle(), movie.getGenre(), movie.getYear()))
        throw DuplicateMovieException();
    this->movies.push_back(movie);
    this->writeToFile();
}

void Repository::deleteMovie(int position) {
    this->movies.erase(this->movies.begin() + position);
    this->writeToFile();
}

void Repository::updateMovie(int position, const Movie& movie) {
//    if (this->search(movie.getTitle(), movie.getGenre(), movie.getYear()))
//        throw DuplicateMovieException();
    bool returnValue;
    int i = 0;
    std::for_each(this->movies.begin(), this->movies.end(), [=, &returnValue, &i](const Movie& m) {
        if (m.getTitle() == movie.getTitle() && m.getGenre() == movie.getGenre() && m.getYear() == movie.getYear() && i != position) returnValue = true; ++i; });
    if (returnValue)
        throw DuplicateMovieException();
    this->movies[position] = movie;
    this->writeToFile();
}

bool Repository::search(const std::string& title, const std::string& genre, int year) {
    bool returnValue = false;
    std::for_each(this->movies.begin(), this->movies.end(), [=, &returnValue](const Movie& movie) {
        if (movie.getTitle() == title && movie.getGenre() == genre && movie.getYear() == year) returnValue = true;});
    return returnValue;
}

Movie& Repository::operator[](int index) {
    return this->movies[index];
}

void Repository::readFromFile()
{
    std::ifstream file(this->filename);

    if (!file.is_open())
        throw FileException("The file could not be opened!");
    Movie movie;
    while (file >> movie)
        if (movie.getLikes() != -1)
            this->movies.push_back(movie);
    file.close();
}

void Repository::writeToFile()
{
    std::ofstream file(this->filename);
    if (!file.is_open())
        throw FileException("The file could not be opened!");
    for (const auto& movie : this->movies)
        file << movie;

    file.close();
}
