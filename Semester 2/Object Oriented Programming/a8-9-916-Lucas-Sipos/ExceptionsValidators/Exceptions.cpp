#include "Exceptions.h"

#include <utility>

FileException::FileException(std::string  msg) : message(std::move(msg))
{
}

const char * FileException::what()
{
    return message.c_str();
}

RepositoryException::RepositoryException() : exception{} {}

RepositoryException::RepositoryException(std::string  msg) : message{std::move( msg )}
{
}

const char * RepositoryException::what()
{
    return this->message.c_str();
}

const char * DuplicateMovieException::what()
{
    return "There is another movie with the same title, genre and year!";
}

const char * IncorrectPosition::what()
{
    return "Incorrect Position";
}
