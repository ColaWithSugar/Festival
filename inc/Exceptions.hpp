#ifndef __EXCEPTIONS_HPP__
#define __EXCEPTIONS_HPP__

#include <stdexcept>

class InvalidDate : public std::out_of_range {
public:
	InvalidDate();
};

class InvalidYear : public std::out_of_range {
public:
	InvalidYear();
};

class InvalidMonth : public std::out_of_range {
public:
	InvalidMonth();
};

class InvalidWeek : public std::out_of_range {
    InvalidWeek();
};

class InvalidDay : public std::out_of_range {
    InvalidDay();
};

class NameNotFound : public std::invalid_argument {
public:
    NameNotFound();
};

class DateNotFound : public std::invalid_argument {
public:
    DateNotFound();
};

class NoMatchingValues : public std::invalid_argument {
public:
    NoMatchingValues();
};

class FestivalExists : public std::invalid_argument {
public:
    FestivalExists();
};

class InvalidInput : public std::invalid_argument {
public:
    InvalidInput();
};

#endif