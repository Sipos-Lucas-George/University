#include "Validator.h"

#include <utility>

Validator::Validator() = default;


Validator::~Validator() = default;

void Validator::validate_movie(const Movie& movie)
{
    std::vector<std::string> errors;
    if (movie.getTitle().empty())
        errors.emplace_back("The title name cannot be less than 1 characters!\n");
    if (!isupper(movie.getGenre()[0]))
        errors.emplace_back("The name of the genre must start with a capital letter!\n");
    if (movie.getYear() < 1889 || movie.getYear() > 2100)
        errors.emplace_back("Year has to be an integer greater than 1889 and smaller than 2100!\n");
    if (movie.getLikes() < 0)
        errors.emplace_back("Likes cannot be a negative integer\n");

    // search for "www" or "http" at the beginning of the source string
    unsigned long long posWww = movie.getTrailer().find("www");
    unsigned long long posHttp = movie.getTrailer().find("http");
    if (posWww != 0 && posHttp != 0)
        errors.emplace_back("The youtube source must start with one of the following strings: \"www\" or \"http\"\n");

    if (!errors.empty())
        throw MovieException(errors);
}


MovieException::MovieException(std::vector<std::string> _errors)
{
    this->errors = std::move(_errors);
}

std::vector<std::string> MovieException::getErrors() const
{
    return this->errors;
}