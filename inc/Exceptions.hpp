/***********************************
 * File Name: Exceptions.hpp
 * Function: declare Exceptions used in the project.
 * Developer(s) & Date: Keqian Tang | 2023-8-1
************************************/

#ifndef __EXCEPTIONS_HPP__
#define __EXCEPTIONS_HPP__

#include <stdexcept>

/*****************************************
Name: InvalidDate
Function: date is invalid
Developer & date: Keqian Tang 2023.8.1
******************************************/
class InvalidDate : public std::out_of_range {
public:
	InvalidDate();
};

/*****************************************
Name: InvalidYear
Function: year is invalid
Developer & date: Keqian Tang 2023.8.1
******************************************/
class InvalidYear : public std::out_of_range {
public:
	InvalidYear();
};

/*****************************************
Name: InvalidMonth
Function: month is invalid
Developer & date: Keqian Tang 2023.8.1
******************************************/
class InvalidMonth : public std::out_of_range {
public:
	InvalidMonth();
};

/*****************************************
Name: InvalidWeek
Function: week is invalid
Developer & date: Keqian Tang 2023.8.1
******************************************/
class InvalidWeek : public std::out_of_range {
    InvalidWeek();
};

/*****************************************
Name: InvalidDay
Function: day is invalid
Developer & date: Keqian Tang 2023.8.1
******************************************/
class InvalidDay : public std::out_of_range {
    InvalidDay();
};

/*****************************************
Name: NameNotFound
Function: name not found
Developer & date: Keqian Tang 2023.8.1
******************************************/
class NameNotFound : public std::invalid_argument {
public:
    NameNotFound();
};

/*****************************************
Name: DateNotFound
Function: date not found
Developer & date: Keqian Tang 2023.8.1
******************************************/
class DateNotFound : public std::invalid_argument {
public:
    DateNotFound();
};

/*****************************************
Name: NoMatchingValues
Function: no matching values
Developer & date: Keqian Tang 2023.8.1
******************************************/
class NoMatchingValues : public std::invalid_argument {
public:
    NoMatchingValues();
};

/*****************************************
Name: FestivalExists
Function: festival already exists.
Developer & date: Keqian Tang 2023.8.1
******************************************/
class FestivalExists : public std::invalid_argument {
public:
    FestivalExists();
};

/*****************************************
Name: InvalidInput
Function: input invalid
Developer & date: Keqian Tang 2023.8.1
******************************************/
class InvalidInput : public std::invalid_argument {
public:
    InvalidInput();
};

#endif