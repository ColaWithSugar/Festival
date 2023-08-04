#include "WeekDay.hpp"
#include "Exceptions.hpp"

WeekDay::WeekDay(const unsigned int Month, const int Week, const DayType Day) 
	: Month(m_Month), Week(m_Week), Day(m_Day) {
	if (IsValidWeekDay(Month, Week, Day) == false) {
		throw InvalidDate();
	}
	m_Month = Month;
	m_Week = Week;
	m_Day = Day;
}

bool WeekDay::IsValidWeekDay(const unsigned int Month, const int Week, const DateInfo::DayType Day) {
	if (Month < DateInfo::MIN_MONTH || Month > DateInfo::MAX_MONTH) {
		return false;
	}
	else if (Week != DateInfo::LAST_ONE && (Week < DateInfo::MIN_WEEK || Week > DateInfo::MAX_WEEK)) {
		return false;
	}
	return true;
}

bool WeekDay::IsValidWeekDay() const {
	return IsValidWeekDay(m_Month, m_Week, m_Day);
}

inline void WeekDay::SetMonth(const unsigned int Month) {
	m_Month = Month;
}

inline void WeekDay::SetWeek(const int Week) {
	m_Week = Week;
}

inline void WeekDay::SetDay(const DayType Day) {
	m_Day = Day;
}

inline void WeekDay::SetWeekDay(const unsigned int Month, const int Week, const DayType Day) {
	if (IsValidWeekDay(Month, Week, Day) == false) {
		throw InvalidDate();
	}
	SetMonth(Month);
	SetWeek(Week);
	SetDay(Day);
}

inline YearDate WeekDay::ToDate(const unsigned int Year,
                                const unsigned int Month,
								const int Week,
								const DayType Day) {
	unsigned int TotalDays = 0;
	for (int TempYear = MIN_YEAR; TempYear < Year; TempYear++)
		TotalDays += DAYS_OF_YEAR[YearDate::IsLeapYear(TempYear)];
	for (int TempMonth = 1; TempMonth < Month; TempMonth++)
		TotalDays += DAYS_OF_MONTH[YearDate::IsLeapYear(Year)][TempMonth];

	if (Week == LAST_ONE)
		TotalDays += DAYS_OF_MONTH[YearDate::IsLeapYear(Year)][Month];
	
	unsigned int DayType = (TotalDays + START_DAY_TYPE) % DAYS_OF_WEEK;
	unsigned int t_Day = 
		((unsigned int)Day - DayType + DAYS_OF_WEEK) % DAYS_OF_WEEK + DAYS_OF_WEEK * (Week - 1) + 1;
	if (Week == LAST_ONE)
		t_Day += DAYS_OF_MONTH[YearDate::IsLeapYear(Year)][Month] + DAYS_OF_WEEK;
	return YearDate(Year, Month, t_Day);
}

YearDate WeekDay::ToDate(const unsigned int Year) const {
	return ToDate(Year, Month, Week, Day);
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
	Stream << aWeekDay.Month << ' ' << aWeekDay.Week << ' ' << DateInfo::EnumToString(aWeekDay.Day);
	return Stream;
}

std::istream& operator>>(std::istream& Stream, WeekDay& aWeekDay) {
	unsigned int Month;
	int Week;
	std::string str_Day;
	char Temp;
	Stream >> Month >> Temp
	       >> Week >> Temp
		   >> str_Day >> Temp;
	aWeekDay.SetWeekDay(Month, Week, DateInfo::StringToEnum(str_Day));
	return Stream;
}