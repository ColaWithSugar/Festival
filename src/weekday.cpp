#include "weekday.hpp"

WeekDay::WeekDay(const unsigned int Month, const unsigned int Week, const unsigned int Day) 
	: Month(m_Month), Week(m_Week), Day(m_Day) {
	m_Month = Month;
	m_Week = Week;
	m_Day = Day;
}

inline void WeekDay::SetMonth(const unsigned int Month) {
	m_Month = Month;
}

inline void WeekDay::SetWeek(const unsigned int Week) {
	m_Week = Week;
}

inline void WeekDay::SetDay(const unsigned int Day) {
	m_Day = Day;
}

inline void WeekDay::SetWeekDay(const unsigned int Month, const unsigned int Week, const unsigned int Day) {
	SetMonth(Month);
	SetWeek(Week);
	SetDay(Day);
}

inline YearDate WeekDay::YearWeekDayToDate(const unsigned int Year,
                                           const unsigned int Month,
										   const unsigned int Week,
										   const unsigned int Day) {
	unsigned int TotalDays = 0;
	for (int TempYear = MIN_YEAR; TempYear < Year; TempYear++)
		TotalDays += 365 + YearDate::IsLeapYear(TempYear);
	for (int TempMonth = 1; TempMonth < Month; TempMonth++)
		TotalDays += DAYS_OF_MONTH[YearDate::IsLeapYear(Year)][TempMonth];

	if (Week == LastOne)
		TotalDays += DAYS_OF_MONTH[YearDate::IsLeapYear(Year)][Month];
	
	unsigned int DayType = (TotalDays + START_DAY_TYPE) % DAYS_OF_WEEK;
	unsigned int t_Day = 
		(Day - DayType + DAYS_OF_WEEK) % DAYS_OF_WEEK + DAYS_OF_WEEK * (Week - 1) + 1;
	return YearDate(Year, Month, t_Day);
}

YearDate WeekDay::YearWeekDayToDate(const unsigned int Year) const {
	return YearWeekDayToDate(Year, Month, Week, Day);
}

inline bool WeekDay::operator==(const WeekDay& aWeekDay) const {
	return (Month == aWeekDay.Month &&
	        Week == aWeekDay.Week &&
			Day == aWeekDay.Day);
}

inline bool WeekDay::operator!=(const WeekDay& aWeekDay) const {
	return !(this->operator==(aWeekDay));
}

inline bool WeekDay::operator<(const WeekDay& aWeekDay) const {
	if (Month != aWeekDay.Month)
		return Month < aWeekDay.Month;
	if (Week != aWeekDay.Week)
		return Week < aWeekDay.Week;
	return Day < aWeekDay.Day;
}

inline bool WeekDay::operator>(const WeekDay& aWeekDay) const {
	return !(this->operator==(aWeekDay) || this->operator<(aWeekDay));
}

inline bool WeekDay::operator<=(const WeekDay& aWeekDay) const {
	return this->operator<(aWeekDay) || this->operator==(aWeekDay);
}

inline bool WeekDay::operator>=(const WeekDay& aWeekDay) const {
	return !(this->operator<(aWeekDay));
}

std::ostream& operator<<(std::ostream& Stream, const WeekDay& aWeekDay) {
	Stream << aWeekDay.Month << '/' << aWeekDay.Week << '/' << aWeekDay.Day << ' ';
}

std::istream& operator>>(std::istream& Stream, WeekDay& aWeekDay) {
	unsigned int Month;
	unsigned int Week;
	unsigned int Day;
	char Temp;
	Stream >> Month >> Temp
	       >> Week >> Temp
		   >> Day >> Temp;
	aWeekDay.SetWeekDay(Month, Week, Day);
}