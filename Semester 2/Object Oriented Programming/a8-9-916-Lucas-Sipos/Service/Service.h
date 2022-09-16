#pragma once
#include "../Repository/Repository.h"
#include "../Repository/WatchList.h"
#include "../Repository/CSVWatchList.h"
#include "../Repository/HTMLWatchList.h"
#include "../ExceptionsValidators/Exceptions.h"
#include "../ExceptionsValidators/Validator.h"

class Service {
private:
    Repository repository;
    WatchList* watchList;

public:
    explicit Service(const Repository& repository, WatchList* watchList);
    ~Service();

    void addRepository(const Movie& movie);
    void deleteRepository(int position);
    void updateRepository(int position, const Movie& movie);
    void incrementLikes(int pos);

    int addWatchList(const Movie& movie);
    int deleteWatchList(int position);
    WatchList* filterMoviesByGenre(const std::string& genre, const std::string& type);

    std::vector<Movie> getAllWatchList() { return this->watchList->getMovies(); }
    std::vector<Movie> getAllRepository() { return this->repository.getMovies(); }
    std::string getType() { return this->watchList->getType(); }

    void watchListSave();
    void watchListOpen();
};
