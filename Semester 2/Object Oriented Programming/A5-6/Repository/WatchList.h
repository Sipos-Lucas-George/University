#pragma once
#include "DynamicVector.h"
#include "../Domain/Movie.h"

class WatchList {
private:
    DynamicVector<Movie> movies;
    int current{};

public:
    WatchList();
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
    void deleteMovie(Movie& movie);

    // play the current movie trailer
    void play();

    // play next current++ movie trailer
    void next();

    // get movie[current]
    Movie& getCurrentMovie();

    // Find a movie by title genre and year
    // Input: title - movie title
    //		  genre - movie genre
    //		  year - movie year
    // Output: true - find, false otherwise
    bool binarySearchMovie(const std::string& title, const std::string& genre, int year);

    // Compares two movies
    // Input:   index - index for this->movies[..]
    //          title - movie title
    //		    genre - movie genre
    //		    year - movie year
    // Output: true - movie == movie, false - otherwise
    static bool compareIfSameMovie(const Movie& movie, const std::string& title, const std::string& genre, int year);

    // Return movie collection
    DynamicVector<Movie> getMovies() const { return this->movies; }
    Movie& operator[](int index);

    int getSize() { return this->movies.getSize(); }
};
