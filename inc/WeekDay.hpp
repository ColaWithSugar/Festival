/***********************************
 * File Name: WeekDay.hpp
 * Function: declare class WeekDay
 * Developer(s) & Date: Keqian Tang | 2023-8-1
************************************/

#ifndef __WEEKDAY_HPP__
#define __WEEKDAY_HPP__

#include "DateInfo.hpp"
#include "YearDate.hpp"
#include <iostream>

/*****************************************
Name: WeekDay
Function: storing which week and which day in wich month
APIs: Check whether the WeekDay is valid (IsValidWeekDay)
      Set the date information (SetWeekDay SetMonth SetWeek SetDay)
	  Generate the date of a WeekDay in a Year (ToDate)
Developer & date: Keqian Tang 2023.7.21
******************************************/
class WeekDay : public DateInfo{
private:
	unsigned int m_Month; //which month
	int m_Week;           //which week
	DayType m_Day;        //which day
public:
	const unsigned int& Month;
	const int& Week;
	const DayType& Day;
	
	//constructor
	WeekDay(const unsigned int Month, const int Week, const DayType Day);
	WeekDay(const WeekDay& Src);

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
	
	//copy
	WeekDay& operator=(const WeekDay& aWeekDay);

	//compare
	bool operator==(const WeekDay& aWeekDay) const;
	bool operator!=(const WeekDay& aWeekDay) const;
	bool operator<(const WeekDay& aWeekDay) const;
	bool operator>(const WeekDay& aWeekDay) const;
	bool operator<=(const WeekDay& aWeekDay) const;
	bool operator>=(const WeekDay& aWeekDay) const;

	//IO
	friend std::ostream& operator<<(std::ostream& Stream, const WeekDay& aWeekDay);
	friend std::istream& operator>>(std::istream& Stream, WeekDay& aWeekDay);
};

#endif