#include "yeardate.hpp"
#include <iostream>

YearDate::YearDate(const unsigned int Year, const unsigned int Month, const unsigned int Day)
	: Date(Month, Day), Year(m_Year) {
	m_Year = Year;
}

bool YearDate::IsLeapYear(const unsigned int Year) {
	if (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0)
		return true;
	return false;
}

bool YearDate::IsLeapYear() const {
	return IsLeapYear(m_Year);
}

bool YearDate::IsValidDate(const unsigned int Year, const unsigned int Month, const unsigned int Day) {
	if (Year < MIN_YEAR || Year > MAX_YEAR)
		return false;
	if (Month < MIN_MONTH || Month > MAX_MONTH)
		return false;
	if (Day < MIN_DAY || Day > DAY_Of_MONTH[IsLeapYear(Year)][Month])
		return false;
	return true;
}

bool YearDate::IsValidDate() const {
	return IsValidDate(m_Year, Month, Day);
}

void YearDate::SetDate(const unsigned int Year, const unsigned int Month, const unsigned int Day) {
	if (IsValidDate(Year, Month, Day) == false)
		throw InvalidDate();
	m_Year = Year;
	Date::SetMonth(Month);
	Date::SetDay(Day);
}

bool YearDate::operator==(const YearDate& aYearDate) const {
	if (m_Year == aYearDate.m_Year && Month == aYearDate.Month && Day == aYearDate.Day)
		return true;
	return false;
}

bool YearDate::operator!=(const YearDate& aYearDate) const {
	if (m_Year == aYearDate.m_Year && Month == aYearDate.Month && Day == aYearDate.Day)
		return false;
	return true;
}

bool YearDate::operator<(const YearDate& aYearDate) const {
	if (m_Year != aYearDate.m_Year)
		return m_Year < aYearDate.m_Year;
	if (Month != aYearDate.Month)
		return Month < aYearDate.Month;
	return Day < aYearDate.Day;
}

bool YearDate::operator>(const YearDate& aYearDate) const {
	if (m_Year != aYearDate.m_Year)
		return m_Year > aYearDate.m_Year;
	if (Month != aYearDate.Month)
		return Month > aYearDate.Month;
	return Day > aYearDate.Day;
}

bool YearDate::operator<=(const YearDate& aYearDate) const {
	if (m_Year != aYearDate.m_Year)
		return m_Year < aYearDate.m_Year;
	if (Month != aYearDate.Month)
		return Month < aYearDate.Month;
	return Day <= aYearDate.Day;
}

bool YearDate::operator>=(const YearDate& aYearDate) const {
	if (m_Year != aYearDate.m_Year)
		return m_Year > aYearDate.m_Year;
	if (Month != aYearDate.Month)
		return Month > aYearDate.Month;
	return Day >= aYearDate.Day;
}

std::ostream& operator<<(std::ostream& Stream, const YearDate& aYearDate) {
	Stream << aYearDate.m_Year << '.' 
	       << aYearDate.Month << '.' 
		   << aYearDate.Day << ' ';
	return Stream;
}

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