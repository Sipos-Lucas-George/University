#include "Service.h"

Service::Service(const Repository& repository, const WatchList& watchList) {
    this->repository = repository;
    this->watchList = watchList;
}

Service::~Service() = default;

int Service::addRepository(const Movie &movie) {
    return this->repository.addMovie(movie);
}

int Service::deleteRepository(int position) {
    if (position < 0 or position >= this->repository.getSize())
        return 0;
    return this->repository.deleteMovie(position);
}

int Service::updateRepository(int position, const Movie& movie) {
    if (position < 0 or position >= this->repository.getSize())
        return 0;
    return this->repository.updateMovie(position, movie);
}

int Service::addWatchList(const Movie &movie) {
    return this->watchList.addMovie(movie);
}

int Service::deleteWatchList(int position) {
    if (position < 0 or position >= this->watchList.getSize())
        return 0;
    return this->watchList.deleteMovieByPos(position);
}

WatchList Service::filterMoviesByGenre(const std::string& genre) {
    WatchList l;
    if (genre.empty()) {
        for (int i = 0; i < this->repository.getSize(); ++i)
                l.addMovie(this->repository[i]);
        return l;
    }
    for (int i = 0; i < this->repository.getSize(); ++i) {
        if (this->repository[i].getGenre() == genre)
            l.addMovie(this->repository[i]);
    }
    return l;
}
