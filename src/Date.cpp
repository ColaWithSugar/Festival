/***********************************
 * File Name: Date.cpp
 * Function: define APIs of class Date.
 * Developer(s) & Date: Keqian Tang | 2023-7-21
************************************/

#include <iostream>
#include "Date.hpp"
#include "Exceptions.hpp"

/*****************************************
Name: Date
Function: constructor of Date
Parameters: Month and Day
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
Date::Date(const unsigned int Month, const unsigned int Day) : Month(m_Month), Day(m_Day) {
	m_Month = Month;
	m_Day   = Day;
}

/*****************************************
Name: Date
Function: copy constructor of Date
Parameters: another Date
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
Date::Date(const Date& Src) : Month(m_Month), Day(m_Day) {
	*this = Src;
}

/*****************************************
Name: IsValidDate
Function: Check wether the date is valid.
Parameters: Month, Day and Leap (wether the year is leap year)
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool Date::IsValidDate(const unsigned int Month, const unsigned int Day, const bool Leap) {
	if (Month < DateInfo::MIN_MONTH || Month > DateInfo::MAX_MONTH)
		return false;
	else if (Day < DateInfo::MIN_DAY || Day > DateInfo::DAYS_OF_MONTH[Leap][Month])
		return false;
	return true;
}

/*****************************************
Name: IsValidDate
Function: Check wether the date is valid.
Parameters: Leap (wether the year is leap year)
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool Date::IsValidDate(const bool Leap) const {
	return IsValidDate(m_Month, m_Day, Leap);
}

/*****************************************
Name: SetMonth
Function: set month
Parameters: Month
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline void Date::SetMonth(const unsigned int Month) {
	m_Month = Month;
}

/*****************************************
Name: SetDay
Function: set day
Parameters: Day
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline void Date::SetDay(const unsigned int Day) {
	m_Day = Day;
}

/*****************************************
Name: SetDay
Function: set date (month and day)
Parameters: Month, Day, Leap (wether the year is leap year)
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline void Date::SetDate(const unsigned int Month, const unsigned int Day, const bool Leap) {
	if (IsValidDate(Month, Day, Leap) == false) {
		throw InvalidDate();
	}
	SetMonth(Month);
	SetDay(Day);
}

/*****************************************
Name: operator=
Function: copy a Date
Parameters: another Date
Return value: the new Date
Developer & date: Keqian Tang 2023.7.21
******************************************/
Date& Date::operator= (const Date& aDate) {
	this->SetDate(aDate.Month, aDate.Day);
	return *this;
}

/*****************************************
Name: operator==
Function: check wether to Dates are the same.
Parameters: another Date
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool Date::operator==(const Date& aDate) const {
	return (this->Month == aDate.Month && this->Day == aDate.Day);
}

/*****************************************
Name: operator!=
Function: check wether two Dates are different.
Parameters: another Date
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool Date::operator!=(const Date& aDate) const {
	return !(this->operator==(aDate));
}

/*****************************************
Name: operator<
Function: check wether this Date is earlier than another.
Parameters: another Date
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool Date::operator<(const Date& aDate) const {
	if (Month != aDate.Month)
		return Month < aDate.Month;
	return Day < aDate.Day;
}

/*****************************************
Name: operator>
Function: check wether this Date is later than another.
Parameters: another Date
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool Date::operator>(const Date& aDate) const {
	return !(this->operator==(aDate) || this->operator<(aDate));
}

/*****************************************
Name: operator<=
Function: check wether this Date is not later than another.
Parameters: another Date
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool Date::operator<=(const Date& aDate) const {
	return !(this->operator>(aDate));
}

/*****************************************
Name: operator>=
Function: check wether this Date is not ealier than another.
Parameters: another Date
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool Date::operator>=(const Date& aDate) const {
	return !(this->operator<(aDate));
}

/*****************************************
Name: operator<<
Function: define the output form
Parameters: Stream, a Date reference.
Return value: std::ostream
Developer & date: Keqian Tang 2023.7.21
******************************************/
std::ostream& operator<<(std::ostream& Stream, const Date& aDate) {
	Stream << aDate.m_Month << '.' << aDate.m_Day;
	return Stream;
}

/*****************************************
Name: operator>>
Function: define the input form
Parameters: Stream, a Date reference.
Return value: std::istream
Developer & date: Keqian Tang 2023.7.21
******************************************/
std::istream& operator>>(std::istream& Stream, Date& aDate) {
	char Temp;
	unsigned int Year;
	unsigned int Month;
	unsigned int Day;
	Stream >> Month >> Temp
		   >> Day;
	aDate.SetDate(Month, Day);
	return Stream;
}
