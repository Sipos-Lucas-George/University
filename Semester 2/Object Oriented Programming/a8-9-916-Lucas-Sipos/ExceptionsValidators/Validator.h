#pragma once
#include "../Domain/Movie.h"
#include <exception>
#include <vector>

class Validator
{
public:
    Validator();
    ~Validator();

    static void validate_movie(const Movie& movie);
};

class MovieException : public std::exception
{
private:
    std::vector<std::string> errors;

public:
    explicit MovieException(std::vector<std::string> _errors);
    std::vector<std::string> getErrors() const;
};
