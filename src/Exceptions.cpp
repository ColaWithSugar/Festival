/***********************************
 * File Name: Exceptions.cpp
 * Function: define exceptions used int the program.
 * Developer(s) & Date: Keqian Tang | 2023-8-1
************************************/

#include "Exceptions.hpp"

/*****************************************
Name: InvalidDate
Function: constructor of InvalidDate
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.1
******************************************/
InvalidDate::InvalidDate() : out_of_range("Date invalid.") { }

/*****************************************
Name: InvalidYear
Function: constructor of InvalidYear
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.1
******************************************/
InvalidYear::InvalidYear() : out_of_range("Year is out of range.") { }

/*****************************************
Name: InvalidMonth
Function: constructor of InvalidMonth
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.1
******************************************/
InvalidMonth::InvalidMonth() : out_of_range("Month is out of range.") { }

/*****************************************
Name: InvalidWeek
Function: constructor of InvalidWeek
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.1
******************************************/
InvalidWeek::InvalidWeek() : out_of_range("Week is out of range.") { }

/*****************************************
Name: InvalidDay
Function: constructor of InvalidDay
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.1
******************************************/
InvalidDay::InvalidDay() : out_of_range("Day invalid.") { }

/*****************************************
Name: NameNotFound
Function: constructor of NameNotFound
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.1
******************************************/
NameNotFound::NameNotFound() : invalid_argument("Name not found.") { }

/*****************************************
Name: DateNotFound
Function: constructor of DateNotFound
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.1
******************************************/
DateNotFound::DateNotFound() : invalid_argument("Date not found.") { }

/*****************************************
Name: NoMatchingValues
Function: constructor of NoMatchingValues
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.1
******************************************/
NoMatchingValues::NoMatchingValues() : invalid_argument("No matching values.") { }

/*****************************************
Name: FestivalExists
Function: constructor of FestivalExists
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.1
******************************************/
FestivalExists::FestivalExists() : invalid_argument("Fesitval already exists.") { }

/*****************************************
Name: InvalidInput
Function: constructor of InvalidInput
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.1
******************************************/
InvalidInput::InvalidInput() : invalid_argument("Input invalid.") { }