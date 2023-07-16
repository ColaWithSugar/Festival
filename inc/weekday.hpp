#ifndef __WEEKDAY_HPP__
#define __WEEKDAY_HPP__

#include "dateinfo.hpp"
#include "yeardate.hpp"
#include <iostream>

class WeekDay : DateInfo{
private:
	unsigned int m_Month;
	unsigned int m_Week;
	unsigned int m_Day;

protected:
	WeekDay(const unsigned int Month, const unsigned int Week, const unsigned int Day);
public:
	const unsigned int& Month;
	const unsigned int& Week;
	const unsigned int& Day;

	void SetMonth(const unsigned int Month);
	void SetWeek(const unsigned int Week);
	void SetDay(const unsigned int Day);
	void SetWeekDay(const unsigned int Month, const unsigned int Week, const unsigned int Day);
	static bool IsValidDate(const unsigned int Month, const unsigned int Week, const unsigned int Day);
	bool IsValidDate() const;

	static YearDate YearWeekDayToDate(const unsigned int Year, 
		                              const unsigned int Month, 
		                              const unsigned int Week, 
		                              const unsigned int Day);
	YearDate YearWeekDayToDate(const unsigned int Year) const;
	
	bool        operator==(const WeekDay& aWeekDay) const;
	bool        operator!=(const WeekDay& aWeekDay) const;
	bool        operator<(const WeekDay& aWeekDay) const;
	bool        operator>(const WeekDay& aWeekDay) const;
	bool        operator<=(const WeekDay& aWeekDay) const;
	bool        operator>=(const WeekDay& aWeekDay) const;
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