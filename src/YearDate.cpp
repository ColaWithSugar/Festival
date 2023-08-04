#include "YearDate.hpp"
#include "Exceptions.hpp"
#include <iostream>

YearDate::YearDate(const unsigned int Year, const unsigned int Month, const unsigned int Day)
	: Date(Month, Day), Year(m_Year) {
	m_Year = Year;
	if (IsValidDate() == false) {
		throw InvalidDate();
	}
}

YearDate::YearDate(const YearDate& aYearDate) : 
				   Date(aYearDate.Month, aYearDate.Day), Year(m_Year) {
	m_Year = aYearDate.Year;
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
	if (Day < MIN_DAY || Day > DAYS_OF_MONTH[IsLeapYear(Year)][Month])
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

const YearDate& YearDate::operator=(const YearDate& aYearDate) {
	SetDate(aYearDate.Year, aYearDate.Month, aYearDate.Day);
	return *this;
}

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