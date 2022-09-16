#pragma once
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>
#include "../Domain/Movie.h"
#include "../ExceptionsValidators/Exceptions.h"

class WatchList {
protected:
    std::vector<Movie> movies;
    int current{};
    std::string type;

public:
    WatchList() = default;
    ~WatchList();

    // Check if the movie already exists, otherwise insert in the container
    // Input: movie - Movie entity
    // Output: 0 - error, 1 - otherwise
    int addMovie(const Movie& movie);

    // Check if the movie exists and remove it from the container
    // Input: position - position to delete in DynamicVector
    // Output: 0 - error, 1 - otherwise
    int deleteMovieByPos(int position);

    // delete movie by finding movie
    void deleteMovie(Movie movie);

    // play the current movie trailer
    void play();

    // play the movie trailer at a position
    void playMovie(int pos);

    // play next current++ movie trailer
    void next();

    // increments movie likes
    void incrementLikes(int pos) { this->movies[pos].incrementLikes(); }

    // get movie[current]
    Movie& getCurrentMovie();

    // Find a movie by title genre and year
    // Input: title - movie title
    //		  genre - movie genre
    //		  year - movie year
    // Output: true - find, false otherwise
    bool search(const std::string& title, const std::string& genre, int year);

    void setMovies(const std::vector<Movie>& newMovies);

    // Return movie collection
    std::vector<Movie> getMovies() const { return this->movies; }
//    Movie& operator[](int index);

    unsigned long long getSize() { return this->movies.size(); }
    void setType(const std::string& typeString) { this->type = typeString; }
    std::string getType() { return this->type; }

    virtual void saveToFile() = 0;
    virtual void openInApp() = 0;
};
