#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
#include "../Domain/Movie.h"
#include "../ExceptionsValidators/Exceptions.h"

class Repository {
private:
    std::vector<Movie> movies;
    std::string filename;

public:
    Repository() = default;
    explicit Repository(std::string);
    ~Repository();

    // Check if the movie already exists, otherwise insert in the container
    // Input: movie - Movie entity
    void addMovie(const Movie& movie);

    // Check if the movie exists and remove it from the container
    // Input: position - position to delete in DynamicVector
    void deleteMovie(int position);

    // Check if the movie exists and update with the new Movie entity
    // Input: m - m to update
    //        movie - new Movie entity
    void updateMovie(int m, const Movie& movie);

    // Find a movie by title genre and year
    // Input: title - movie title
    //		  genre - movie genre
    //		  year - movie year
    // Output: true - find, false otherwise
    bool search(const std::string& title, const std::string& genre, int year);

    // Return movie collection
    std::vector<Movie> getMovies() const { return this->movies; }
    unsigned long long getSize(){ return this->movies.size(); }
    std::string getFileName() { return this->filename; }
    Movie& operator[](int index);

private:
    void readFromFile();
    void writeToFile();
};
