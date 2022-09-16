#pragma once
#include <iostream>

class Movie {
private:
    std::string title;
    std::string genre;
    int year;
    int likes;
    std::string trailer;
    int ifLiked;

public:
    Movie();
    Movie(std::string,std::string,int,int,std::string);
    ~Movie();

    std::string getTitle() const { return this->title; }
    std::string getGenre() const { return this->genre; }
    int getYear() const { return this->year; }
    int getLikes() const { return this->likes; }
    std::string getTrailer() const { return this->trailer; }

    void incrementLikes();
    void playTrailer() const;
    std::string toString();
};
