#include <iostream>
#include "date.hpp"

Date::Date(const unsigned int Month, const unsigned int Day) : Month(m_Month), Day(m_Day) {
	m_Month = Month;
	m_Day   = Day;
}

bool Date::IsValidDate(const unsigned int Month, const unsigned int Day, const bool Leap = 1) {
	if (Month < DateInfo::MIN_MONTH || Month > DateInfo::MAX_MONTH)
		return false;
	else if (Day < DateInfo::MIN_DAY || Day > DateInfo::DAY_Of_MONTH[Leap][Month])
		return false;
	return true;
}

bool Date::IsValidDate(const bool Leap = 1) const {
	return IsValidDate(m_Month, m_Day, Leap);
}

inline void Date::SetMonth(const unsigned int Month) {
	m_Month = Month;
}

inline void Date::SetDay(const unsigned int Day) {
	m_Day = Day;
}

void Date::SetDate(const unsigned int Month, const unsigned int Day, const bool Leap = 1) {
	if (IsValidDate(Month, Day, Leap) == false) {
		throw InvalidDate();
	}
	SetMonth(Month);
	SetDay(Day);
}

bool Date::operator==(const Date& aDate) const {
	if (this->Month == aDate.m_Month && this->Day == aDate.m_Day)
		return true;
	return false;
}

bool Date::operator!=(const Date& aDate) const {
	if (this->Month == aDate.m_Month && this->Day == aDate.m_Day)
		return false;
	return true;
}

bool Date::operator<(const Date& aDate) const {
	if (this->Month < aDate.m_Month)
		return true;
	else if (this->Month > aDate.m_Month)
		return false;
	else
		return this->Day < aDate.m_Day;
}

bool Date::operator>(const Date& aDate) const {
	if (this->Month < aDate.m_Month)
		return false;
	else if (this->Month > aDate.m_Month)
		return true;
	else
		return this->Day > aDate.m_Day;
}

bool Date::operator<=(const Date& aDate) const {
	if (this->Month < aDate.m_Month)
		return true;
	else if (this->Month > aDate.m_Month)
		return false;
	else
		return this->Day <= aDate.m_Day;
}

bool Date::operator>=(const Date& aDate) const {
	if (this->Month < aDate.m_Month)
		return false;
	else if (this->Month > aDate.m_Month)
		return true;
	else
		return this->Day >= aDate.m_Day;
}

std::ostream& operator<<(std::ostream& Stream, const Date& aDate) {
	Stream << aDate.m_Month << '.' << aDate.m_Day << ' ';
	return Stream;
}

std::istream& operator>>(std::istream& Stream, Date& aDate) {
	char Temp;
	unsigned int Year;
	unsigned int Month;
	unsigned int Day;
	Stream >> Month >> Temp
		   >> Day   >> Temp;
	aDate.SetDate(Month, Day);
	return Stream;
}


InvalidDate::InvalidDate() : std::invalid_argument("Date invalid.") { }