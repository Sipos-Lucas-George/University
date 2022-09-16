#pragma once
#include <exception>
#include <string>

class RepositoryException : public std::exception
{
protected:
    std::string message;

public:
    RepositoryException();
    explicit RepositoryException(std::string  msg);
    ~RepositoryException() override = default;
    virtual const char* what();
};

class DuplicateMovieException : public RepositoryException
{
public:
    const char* what() override;
};

class FileException : public std::exception
{
protected:
    std::string message;

public:
    explicit FileException(std::string  msg);
    virtual const char* what();
};


class IncorrectPosition : public RepositoryException
{
public:
    const char* what() override;
};
