/***********************************
 * File Name: YearDate.hpp
 * Function: declare class YearDate
 * Developer(s) & Date: Keqian Tang | 2023-8-1
************************************/

#ifndef __YEARDATE_HPP__
#define __YEARDATE_HPP__

#include "Date.hpp"

/*****************************************
Name: YearDate
Function: storing a date with year
APIs: Check whether the date is valid (IsValidDate).
	  Check whether the year is a leap year (IsLeapYear)
      Set the date information (SetYearDate SetYear SetMonth SetDay)
Developer & date: Keqian Tang 2023.7.21
******************************************/
class YearDate : public Date {
private:
	unsigned int m_Year; //year of the date

public:
	const unsigned int& Year;

	//constructors
	YearDate(const unsigned int Year = MIN_YEAR, 
	         const unsigned int Month = MIN_MONTH, 
			 const unsigned int Day = MIN_DAY);
	YearDate(const YearDate& Src);

	void SetDate(const unsigned int Year, const unsigned int Month, const unsigned int Day);
	void SetYear(const unsigned int Year);

	static bool IsLeapYear(const unsigned int Year);
	bool        IsLeapYear() const;
	static bool IsValidDate(const unsigned int Year, const unsigned int Month, const unsigned int Day);
	bool        IsValidDate() const;
	
	//copy
	YearDate& operator=(const YearDate& aYearDate);

	int operator-(const YearDate& aYearDate) const;

	//compare
	bool operator==(const YearDate& aYearDate) const;
	bool operator!=(const YearDate& aYearDate) const;
	bool operator<(const YearDate& aYearDate) const;
	bool operator>(const YearDate& aYearDate) const;
	bool operator<=(const YearDate& aYearDate) const;
	bool operator>=(const YearDate& aYearDate) const;

	//IO
	friend std::ostream& operator<<(std::ostream& Stream, const YearDate& aYearDate);
	friend std::istream& operator>>(std::istream& Stream, YearDate& aYearDate);
};

#endif