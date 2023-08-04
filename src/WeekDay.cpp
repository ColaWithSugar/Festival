#include "WeekDay.hpp"
#include "Exceptions.hpp"

/*****************************************
Name: WeekDay
Function: constructor of WeekDay
Parameters: Month, Week and Day
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
WeekDay::WeekDay(const unsigned int Month, const int Week, const DayType Day) 
	: Month(m_Month), Week(m_Week), Day(m_Day) {
	if (IsValidWeekDay(Month, Week, Day) == false) {
		throw InvalidDate();
	}
	m_Month = Month;
	m_Week = Week;
	m_Day = Day;
}

/*****************************************
Name: WeekDay
Function: copy constructor of WeekDay
Parameters: another WeekDay
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
WeekDay::WeekDay(const WeekDay& Src)
	: Month(m_Month), Week(m_Week), Day(m_Day) {
	*this = Src;
}

/*****************************************
Name: IsValidWeekDay
Function: check whether the weekday is valid.
Parameters: Month, Week and Day
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool WeekDay::IsValidWeekDay(const unsigned int Month, const int Week, const DateInfo::DayType Day) {
	if (Month < DateInfo::MIN_MONTH || Month > DateInfo::MAX_MONTH) {
		return false;
	}
	else if (Week != DateInfo::LAST_ONE && (Week < DateInfo::MIN_WEEK || Week > DateInfo::MAX_WEEK)) {
		return false;
	}
	return true;
}

/*****************************************
Name: IsValidWeekDay
Function: check whether the weekday is valid.
Parameters: None
Return value: bool (yess or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool WeekDay::IsValidWeekDay() const {
	return IsValidWeekDay(m_Month, m_Week, m_Day);
}

/*****************************************
Name: SetMonth
Function: set the month of WeekDay
Parameters: Month
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline void WeekDay::SetMonth(const unsigned int Month) {
	m_Month = Month;
}

/*****************************************
Name: SetWeek
Function: set the week of WeekDay
Parameters: Week
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline void WeekDay::SetWeek(const int Week) {
	m_Week = Week;
}

/*****************************************
Name: SetDay
Function: set the day of WeekDay
Parameters: Day
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline void WeekDay::SetDay(const DayType Day) {
	m_Day = Day;
}

/*****************************************
Name: SetWeekDay
Function: set the WeekDay
Parameters: Month, Week and Day
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline void WeekDay::SetWeekDay(const unsigned int Month, const int Week, const DayType Day) {
	if (IsValidWeekDay(Month, Week, Day) == false) {
		throw InvalidDate();
	}
	SetMonth(Month);
	SetWeek(Week);
	SetDay(Day);
}

/*****************************************
Name: ToDate
Function: transfer WeekDay to YearDate providing the year.
Parameters: Year, Month, Week and Day.
Return value: YearDate
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline YearDate WeekDay::ToDate(const unsigned int Year,
                                const unsigned int Month,
								const int Week,
								const DayType Day) {
	//Get totaldays from 1900.1.1
	unsigned int TotalDays = 0;
	for (int TempYear = MIN_YEAR; TempYear < Year; TempYear++)
		TotalDays += DAYS_OF_YEAR[YearDate::IsLeapYear(TempYear)];
	for (int TempMonth = 1; TempMonth < Month; TempMonth++)
		TotalDays += DAYS_OF_MONTH[YearDate::IsLeapYear(Year)][TempMonth];
	if (Week == LAST_ONE)
		TotalDays += DAYS_OF_MONTH[YearDate::IsLeapYear(Year)][Month];
	
	//calculate day
	unsigned int DayType = (TotalDays + START_DAY_TYPE) % DAYS_OF_WEEK;
	unsigned int t_Day = 
		((unsigned int)Day - DayType + DAYS_OF_WEEK) % DAYS_OF_WEEK + DAYS_OF_WEEK * (Week - 1) + 1;
	if (Week == LAST_ONE)
		t_Day += DAYS_OF_MONTH[YearDate::IsLeapYear(Year)][Month] + DAYS_OF_WEEK;
	return YearDate(Year, Month, t_Day);
}

/*****************************************
Name: ToDate
Function: transfer WeekDay to YearDate providing the year.
Parameters: Year
Return value: YearDate
Developer & date: Keqian Tang 2023.7.21
******************************************/
YearDate WeekDay::ToDate(const unsigned int Year) const {
	return ToDate(Year, Month, Week, Day);
}

/*****************************************
Name: operator=
Function: copy a WeekDay
Parameters: another WeekDay
Return value: the new WeekDay
Developer & date: Keqian Tang 2023.7.21
******************************************/
WeekDay& WeekDay::operator=(const WeekDay& aWeekDay) {
	SetWeekDay(aWeekDay.Month, aWeekDay.Week, aWeekDay.Day);
	return *this;
}

/*****************************************
Name: operator==
Function: check whether to WeekDays are the same.
Parameters: another WeekDay
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline bool WeekDay::operator==(const WeekDay& aWeekDay) const {
	return (Month == aWeekDay.Month &&
	        Week == aWeekDay.Week &&
			Day == aWeekDay.Day);
}

/*****************************************
Name: operator!=
Function: check whether to WeekDays are different.
Parameters: another WeekDay
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline bool WeekDay::operator!=(const WeekDay& aWeekDay) const {
	return !(this->operator==(aWeekDay));
}

/*****************************************
Name: operator<
Function: check whether this WeekDay is earlier.
Parameters: another WeekDay
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline bool WeekDay::operator<(const WeekDay& aWeekDay) const {
	if (Month != aWeekDay.Month)
		return Month < aWeekDay.Month;
	if (Week != aWeekDay.Week)
		return Week < aWeekDay.Week;
	return Day < aWeekDay.Day;
}

/*****************************************
Name: operator>
Function: check whether this WeekDay is later.
Parameters: another WeekDay
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline bool WeekDay::operator>(const WeekDay& aWeekDay) const {
	return !(this->operator==(aWeekDay) || this->operator<(aWeekDay));
}

/*****************************************
Name: operator<=
Function: check whether this WeekDay is not later.
Parameters: another WeekDay
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline bool WeekDay::operator<=(const WeekDay& aWeekDay) const {
	return this->operator<(aWeekDay) || this->operator==(aWeekDay);
}

/*****************************************
Name: operator>=
Function: check whether this WeekDay is not earlier.
Parameters: another WeekDay
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline bool WeekDay::operator>=(const WeekDay& aWeekDay) const {
	return !(this->operator<(aWeekDay));
}

/*****************************************
Name: operator<<
Function: set the output form of WeekDay
Parameters: an ostream, target WeekDay
Return value: ostream
Developer & date: Keqian Tang 2023.7.21
******************************************/
std::ostream& operator<<(std::ostream& Stream, const WeekDay& aWeekDay) {
	Stream << aWeekDay.Month << ' ' << aWeekDay.Week << ' ' << DateInfo::EnumToString(aWeekDay.Day);
	return Stream;
}

/*****************************************
Name: operator>>
Function: set the input form of WeekDay
Parameters: an istream, target WeekDay
Return value: istream
Developer & date: Keqian Tang 2023.7.21
******************************************/
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