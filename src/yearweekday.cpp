#include "yearweekday.hpp"

YearWeekDay::YearWeekDay(const unsigned int Year, 
			const unsigned int Month,
			const unsigned int Week, 
			const unsigned int Day) 
			: WeekDay(Month, Week, Day), Year(m_Year) {
	m_Year = Year;
}

void YearWeekDay::SetYear(const unsigned int Year) {
	m_Year = Year;
}

void YearWeekDay::SetYearWeekDay(const unsigned int Year,
                                 const unsigned int Month,
								 const unsigned int Week,
								 const unsigned int Day) {
	m_Year = Year;
	WeekDay::SetWeekDay(Month, Week, Day);
}

YearDate YearWeekDay::ToDate() const {
	return WeekDay::ToDate(m_Year);
}

inline bool YearWeekDay::operator==(const YearWeekDay& aYearWeekDay) const {
	return (Year  == aYearWeekDay.Year &&
	        Month == aYearWeekDay.Month &&
			Week  == aYearWeekDay.Week &&
			Day   == aYearWeekDay.Day);
}

inline bool YearWeekDay::operator!=(const YearWeekDay& aYearWeekDay) const {
	return !(this->operator==(aYearWeekDay));
}

inline bool YearWeekDay::operator<(const YearWeekDay& aYearWeekDay) const {
	return ToDate() < aYearWeekDay.ToDate();
}

inline bool YearWeekDay::operator>(const YearWeekDay& aYearWeekDay) const {
	return !(this->operator<(aYearWeekDay) || this->operator==(aYearWeekDay));
}

inline bool YearWeekDay::operator<=(const YearWeekDay& aYearWeekDay) const {
	return !(this->operator>(aYearWeekDay));
}

inline bool YearWeekDay::operator>=(const YearWeekDay& aYearWeekDay) const {
	return !(this->operator<(aYearWeekDay));
}