#ifndef __WEEKDAY_HPP__
#define __WEEKDAY_HPP__

#include "DateInfo.hpp"
#include "YearDate.hpp"
#include <iostream>

class WeekDay : public DateInfo{
private:
	unsigned int m_Month;
	int m_Week;
	DayType m_Day;
public:
	const unsigned int& Month;
	const int& Week;
	const DayType& Day;

	WeekDay(const unsigned int Month, const int Week, const DayType Day);
	
	void SetMonth(const unsigned int Month);
	void SetWeek(const int Week);
	void SetDay(const DayType Day);
	void SetWeekDay(const unsigned int Month, const int Week, const DayType Day);
	static bool IsValidWeekDay(const unsigned int Month, const int Week, const DateInfo::DayType Day);
	bool IsValidWeekDay() const;

	static YearDate ToDate(const unsigned int Year, 
		                   const unsigned int Month, 
		                   const int Week, 
	                       const DayType Day);
	YearDate ToDate(const unsigned int Year) const;
	
	bool operator==(const WeekDay& aWeekDay) const;
	bool operator!=(const WeekDay& aWeekDay) const;
	bool operator<(const WeekDay& aWeekDay) const;
	bool operator>(const WeekDay& aWeekDay) const;
	bool operator<=(const WeekDay& aWeekDay) const;
	bool operator>=(const WeekDay& aWeekDay) const;
	// friend bool operator==(const WeekDay& WeekDayA, const WeekDay& WeekDayB);
	// friend bool operator==(const WeekDay& WeekDayA, const WeekDay& WeekDayB);
	// friend bool operator<(const WeekDay& WeekDayA, const WeekDay& WeekDayB);
	// friend bool operator>(const WeekDay& WeekDayA, const WeekDay& WeekDayB);
	// friend bool operator<=(const WeekDay& WeekDayA, const WeekDay& WeekDayB);
	// friend bool operator>=(const WeekDay& WeekDayA, const WeekDay& WeekDayB);

	friend std::ostream& operator<<(std::ostream& Stream, const WeekDay& aWeekDay);
	friend std::istream& operator>>(std::istream& Stream, WeekDay& aWeekDay);
};

#endif