#include "Service.h"

Service::Service(const Repository& repository, WatchList* watchList) {
    this->repository = repository;
    this->watchList = watchList;
}

Service::~Service() = default;

void Service::addRepository(const Movie &movie) {
    Validator::validate_movie(movie);
    this->repository.addMovie(movie);
}

void Service::deleteRepository(int position) {
    (position < 0 or position >= this->repository.getSize()) ? throw IncorrectPosition() : this->repository.deleteMovie(position);
}

void Service::updateRepository(int position, const Movie& movie) {
    Validator::validate_movie(movie);
    (position < 0 or position >= this->repository.getSize()) ? throw IncorrectPosition() : this->repository.updateMovie(position, movie);
}

void Service::incrementLikes(int pos) {
    this->repository[pos].incrementLikes();
}

int Service::addWatchList(const Movie &movie) {
    return this->watchList->addMovie(movie);
}

int Service::deleteWatchList(int position) {
    return (position < 0 or position >= this->watchList->getSize()) ? 0 : this->watchList->deleteMovieByPos(position);
}

WatchList* Service::filterMoviesByGenre(const std::string& genre, const std::string& type) {
    std::vector<Movie> l;
    if (genre.empty())
        l = this->repository.getMovies();
    else {
        for (const auto& i : this->repository.getMovies())
            if (i.getGenre() == genre)
                l.push_back(i);
    }
    WatchList* newWL;
    if (type == "csv"){
        newWL = new CSVWatchList();
        newWL->setType("csv");
    }
    else {
        newWL = new HTMLWatchList();
        newWL->setType("html");
    }
    newWL->setMovies(l);
    return newWL;
}

void Service::watchListSave()
{
    this->watchList->saveToFile();
}

void Service::watchListOpen()
{
    this->watchList->openInApp();
}
