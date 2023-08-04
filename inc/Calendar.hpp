/***********************************
 * File Name: Calendar.hpp
 * Function: declare class Calendar
 * Developer(s) & Date: Keqian Tang | 2023-8-1
************************************/


#ifndef __CALENDAR_HPP__
#define __CALENDAR_HPP__

#include "DateInfo.hpp"
#include "YearDate.hpp"
#include "Festival.hpp"
#include <vector>
#include <utility>

class Calendar : public DateInfo{
private:
	unsigned int m_Month; //month of the calendar
	unsigned int m_Year; //year of the calendar
	unsigned int m_StartDay; //start day type of the month
	unsigned int m_IsLeap; //whether the year is a leap year
protected:
	std::vector<std::pair<std::string, YearDate>> m_Festivals; //storing festivals
public:
	const unsigned int& Month;
	const unsigned int& Year;
	const unsigned int& StartDay;
	const unsigned int& IsLeap;
	std::vector<std::pair<std::string, YearDate>>& Festivals;
	
	//constructors
	Calendar(const unsigned int Year, const unsigned int Month);
	Calendar(const Calendar& Src);

	//destructor
	~Calendar();

	void Set(const unsigned int Year, const unsigned int Month);
	void LoadFestivals(const std::vector<std::shared_ptr<Festival>>& Data);
	const Calendar& operator=(const Calendar& aCalendar);
};

#endif