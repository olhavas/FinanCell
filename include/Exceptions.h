#ifndef Exceptions_h
#define Exceptions_h
#include <stdexcept>

class InvalidAmountException : public std::invalid_argument
{
public:
    InvalidAmountException(const std::string &message) : std::invalid_argument(message) {}
};
class NonNumberAmountInputException : public std::invalid_argument
{
public:
    NonNumberAmountInputException(const std::string &message) : std::invalid_argument(message) {}
};
class InvalidDespriptionException : public std::exception
{
public:

    const char * what () const throw () {
        return "Description cannot be empty.";
    }
};

#endif