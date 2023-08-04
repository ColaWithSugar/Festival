/***********************************
 * File Name: Calendar.cpp
 * Function: define APIs of Calendar
 * Developer(s) & Date: Keqian Tang | 2023-8-1
************************************/

#include "Calendar.hpp"
#include "Exceptions.hpp"
#include <stdexcept>
#include <algorithm>

/*****************************************
Name: Calendar
Function: constructor of Calendar
Parameters: Year and Month
Return value: None
Developer & date: Keqian Tang 2023.8.1
******************************************/
Calendar::Calendar(const unsigned int Year, const unsigned int Month) : 
	Year(m_Year), Month(m_Month), StartDay(m_StartDay), IsLeap(m_IsLeap), Festivals(m_Festivals) {
	this->Set(Year, Month);
	return;
}

/*****************************************
Name: ~Calendar
Function: destructor of Calendar
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.1
******************************************/
Calendar::~Calendar() {
	m_Festivals.clear();
}

/*****************************************
Name: Set
Function: set the year and month of the calendar
Parameters: Year and Month
Return value: None
Developer & date: Keqian Tang 2023.8.1
******************************************/
void Calendar::Set(const unsigned int Year, const unsigned int Month) {
	if (Year < MIN_YEAR || Year > MAX_YEAR)
		throw InvalidYear();
	if (Month < MIN_MONTH || Month > MAX_MONTH)
		throw InvalidMonth();
	m_Year = Year;
	m_Month = Month;
	m_IsLeap = YearDate::IsLeapYear(Year);
	unsigned int TotalDays = 0;
	for (unsigned int TempYear = MIN_YEAR; TempYear < Year; TempYear++) {
		TotalDays += DAYS_OF_YEAR[YearDate::IsLeapYear(TempYear)];
	}
	for (unsigned int TempMonth = MIN_MONTH; TempMonth < Month; TempMonth++) {
		TotalDays += DAYS_OF_MONTH[IsLeap][TempMonth];
	}
	m_StartDay = (START_DAY_TYPE + TotalDays) % 7;
}

/*****************************************
Name: LoadFestival
Function: load festivals in this month
Parameters: a vector storing festivals
Return value: None
Developer & date: Keqian Tang 2023.8.1
******************************************/
void Calendar::LoadFestivals(const std::vector<std::shared_ptr<Festival>>& Data) {
	Festival::SortByYear(m_Year);
	m_Festivals.clear();
	for (auto& n : Data) {
		YearDate Temp = (*n).ToDate(m_Year);
		if (Temp.Month == m_Month) {
			m_Festivals.push_back(std::pair<std::string, YearDate>((*n).Name, Temp));
		}
	}
}