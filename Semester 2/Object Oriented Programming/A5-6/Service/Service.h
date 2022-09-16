#pragma once
#include "../Repository/Repository.h"
#include "../Repository/WatchList.h"

class Service {
private:
    Repository repository;
    WatchList watchList;

public:
    explicit Service(const Repository& repository, const WatchList& watchList);
    ~Service();

    int addRepository(const Movie& movie);
    int deleteRepository(int position);
    int updateRepository(int position, const Movie& movie);

    int addWatchList(const Movie& movie);
    int deleteWatchList(int position);
    WatchList filterMoviesByGenre(const std::string& genre);

    DynamicVector<Movie> getAllWatchList() { return this->watchList.getMovies(); }
    DynamicVector<Movie> getAllRepository() { return this->repository.getMovies(); }
    Repository getRepository() { return this->repository; }
    WatchList getWatchList() { return this->watchList; }
};
