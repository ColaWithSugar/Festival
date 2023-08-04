#include "YearDate.hpp"
#include "Exceptions.hpp"
#include <iostream>

/*****************************************
Name: YearDate
Function: constructor of YearDate
Parameters: Year, Month, Day
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
YearDate::YearDate(const unsigned int Year, const unsigned int Month, const unsigned int Day)
	: Date(Month, Day), Year(m_Year) {
	m_Year = Year;
	if (IsValidDate() == false) {
		throw InvalidDate();
	}
}

/*****************************************
Name: YearDate
Function: copy constructor of YearDate
Parameters: a YearDate
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
YearDate::YearDate(const YearDate& Src) : 
				   Date(Src.Month, Src.Day), Year(m_Year) {
	m_Year = Src.Year;
}

/*****************************************
Name: IsLeapYear
Function: check whether the year is a leap year.
Parameters: Year
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool YearDate::IsLeapYear(const unsigned int Year) {
	if (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0)
		return true;
	return false;
}

/*****************************************
Name: IsLeapYear
Function: check whether the year is a leap year.
Parameters: None
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool YearDate::IsLeapYear() const {
	return IsLeapYear(m_Year);
}

/*****************************************
Name: IsValidDate
Function: check whether the date is valid.
Parameters: Year, Month, Day
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool YearDate::IsValidDate(const unsigned int Year, const unsigned int Month, const unsigned int Day) {
	if (Year < MIN_YEAR || Year > MAX_YEAR)
		return false;
	if (Month < MIN_MONTH || Month > MAX_MONTH)
		return false;
	if (Day < MIN_DAY || Day > DAYS_OF_MONTH[IsLeapYear(Year)][Month])
		return false;
	return true;
}

/*****************************************
Name: IsValidDate
Function: check whether the date is valid.
Parameters: None
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool YearDate::IsValidDate() const {
	return IsValidDate(m_Year, Month, Day);
}

/*****************************************
Name: SetDate
Function: set the date of YearDate
Parameters: Year, Month, Day
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
void YearDate::SetDate(const unsigned int Year, const unsigned int Month, const unsigned int Day) {
	if (IsValidDate(Year, Month, Day) == false)
		throw InvalidDate();
	m_Year = Year;
	Date::SetMonth(Month);
	Date::SetDay(Day);
}

/*****************************************
Name: operator=
Function: copy a YearDate
Parameters: another YearDate
Return value: the new YearDate
Developer & date: Keqian Tang 2023.7.21
******************************************/
YearDate& YearDate::operator=(const YearDate& aYearDate) {
	SetDate(aYearDate.Year, aYearDate.Month, aYearDate.Day);
	return *this;
}

/*****************************************
Name: operator-
Function: get the number of days between two dates.
Parameters: another YearDate
Return value: the number of days between two dates.
Developer & date: Keqian Tang 2023.7.21
******************************************/
int YearDate::operator-(const YearDate& aYearDate) const {
	bool IsSwapped = false;
	int TotalDays = 0;
	YearDate Date1(aYearDate);
	YearDate Date2(*this);
	if (aYearDate > *this) {
		YearDate Temp(aYearDate);
		Date2 = Date1;
		Date1 = Temp;
		IsSwapped = true;
		std::cout << "QHJKHGKJHJKHFKJH" << std::endl;
	}
	for (unsigned int t_Year = Date1.Year + 1; t_Year < Date2.Year; t_Year++) {
		TotalDays += DAYS_OF_YEAR[IsLeapYear(t_Year)];
	}
	if (Date1.Year == Date2.Year) {
		for (int t_Month = Date1.Month; t_Month < Date2.Month; t_Month++) {
			TotalDays += DAYS_OF_MONTH[IsLeapYear(Date1.Year)][t_Month];
		}
		TotalDays += Date2.Day - Date1.Day;
	} else {
		for(unsigned int t_Month = Date1.Month; t_Month <= MAX_MONTH; t_Month++) {
			TotalDays += DAYS_OF_MONTH[IsLeapYear(Date1.Year)][t_Month];
		}
		for (unsigned int t_Month = MIN_MONTH; t_Month < Date2.Month; t_Month++) {
			TotalDays += DAYS_OF_MONTH[IsLeapYear(Date2.Year)][t_Month];
		}
		TotalDays += (int)Date2.Day - (int)Date1.Day;
	}
	return (IsSwapped ? -TotalDays : TotalDays);
}

/*****************************************
Name: operator==
Function: check wether to Dates are the same.
Parameters: another YearDate
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool YearDate::operator==(const YearDate& aYearDate) const {
	if (m_Year == aYearDate.m_Year && Month == aYearDate.Month && Day == aYearDate.Day)
		return true;
	return false;
}

/*****************************************
Name: operator!=
Function: check wether two Dates are different.
Parameters: another YearDate
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool YearDate::operator!=(const YearDate& aYearDate) const {
	if (m_Year == aYearDate.m_Year && Month == aYearDate.Month && Day == aYearDate.Day)
		return false;
	return true;
}

/*****************************************
Name: operator<
Function: check wether this YearDate is earlier than another.
Parameters: another YearDate
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool YearDate::operator<(const YearDate& aYearDate) const {
	if (m_Year != aYearDate.m_Year)
		return m_Year < aYearDate.m_Year;
	if (Month != aYearDate.Month)
		return Month < aYearDate.Month;
	return Day < aYearDate.Day;
}

/*****************************************
Name: operator>
Function: check wether this YearDate is later than another.
Parameters: another YearDate
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool YearDate::operator>(const YearDate& aYearDate) const {
	if (m_Year != aYearDate.m_Year)
		return m_Year > aYearDate.m_Year;
	if (Month != aYearDate.Month)
		return Month > aYearDate.Month;
	return Day > aYearDate.Day;
}

/*****************************************
Name: operator<=
Function: check wether this YearDate is not later than another.
Parameters: another YearDate
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool YearDate::operator<=(const YearDate& aYearDate) const {
	if (m_Year != aYearDate.m_Year)
		return m_Year < aYearDate.m_Year;
	if (Month != aYearDate.Month)
		return Month < aYearDate.Month;
	return Day <= aYearDate.Day;
}

/*****************************************
Name: operator>=
Function: check wether this YearDate is not ealier than another.
Parameters: another YearDate
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool YearDate::operator>=(const YearDate& aYearDate) const {
	if (m_Year != aYearDate.m_Year)
		return m_Year > aYearDate.m_Year;
	if (Month != aYearDate.Month)
		return Month > aYearDate.Month;
	return Day >= aYearDate.Day;
}

/*****************************************
Name: operator<<
Function: set the output form
Parameters: Stream, a Date reference.
Return value: std::ostream
Developer & date: Keqian Tang 2023.7.21
******************************************/
std::ostream& operator<<(std::ostream& Stream, const YearDate& aYearDate) {
	Stream << aYearDate.m_Year << '.' 
	       << aYearDate.Month << '.' 
		   << aYearDate.Day << ' ';
	return Stream;
}

/*****************************************
Name: operator>>
Function: set the input form
Parameters: Stream, a Date reference.
Return value: std::istream
Developer & date: Keqian Tang 2023.7.21
******************************************/
std::istream& operator>>(std::istream& Stream, YearDate& aYearDate) {
	char Temp;
	unsigned int Year;
	unsigned int Month;
	unsigned int Day;
	Stream >> Year >> Temp
	       >> Month >> Temp
	       >> Day;
	aYearDate.SetDate(Year, Month, Day);
	return Stream;
}