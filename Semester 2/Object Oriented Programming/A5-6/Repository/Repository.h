#pragma once
#include "../Domain/Movie.h"
#include "DynamicVector.h"

class Repository {
private:
    DynamicVector<Movie> movies;

public:
    Repository();
    ~Repository();

    // Check if the movie already exists, otherwise insert in the container
    // Input: movie - Movie entity
    // Output: 0 - error, 1 - otherwise
    int addMovie(const Movie& movie);

    // Check if the movie exists and remove it from the container
    // Input: position - position to delete in DynamicVector
    // Output: 1
    int deleteMovie(int position);

    // Check if the movie exists and update with the new Movie entity
    // Input: position - position to update
    //        movie - new Movie entity
    // Output: 0 - error, 1 - otherwise
    int updateMovie(int position, const Movie& movie);

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

    // finds the position of a movie and returns its index
    int findPositionOfMovie(const Movie& movie);

    // Return movie collection
    DynamicVector<Movie> getMovies() const { return this->movies; }
    int getSize(){ return this->movies.getSize(); }
    Movie& operator[](int index);
};
