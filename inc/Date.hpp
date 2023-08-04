/***********************************
 * File Name: Date.hpp
 * Function: declare class Date
 * Developer(s) & Date: Keqian Tang | 2023-7-21
************************************/

#ifndef __DATE_HPP__
#define __DATE_HPP__

#include <iostream>
#include <stdexcept>
#include "DateInfo.hpp"

/*****************************************
Name: Date
Function: storing a date without year
APIs: Check whether the date is valid (IsValidDate).
      Set the date information (SetDate SetMonth SetDay)
Developer & date: Keqian Tang 2023.7.21
******************************************/
class Date : public DateInfo{
private:
	unsigned int m_Month; //Month of the date
	unsigned int m_Day;   //Day of the date

public:
	const unsigned int& Month;
	const unsigned int& Day;
	
	//constructors
	Date(const unsigned int Month, const unsigned int Day);
	Date(const Date& Src);

	void SetMonth(const unsigned int Day);
	void SetDay(const unsigned int Day);
	void SetDate(const unsigned int Month, const unsigned int Day, const bool Leap = true);

	static bool IsValidDate(const unsigned int Month, const unsigned int Day, const bool Leap = true);
	bool IsValidDate(const bool Leap = true) const;

	//copy
	Date& operator= (const Date& aDate);

	//compare
	bool operator==(const Date& aDate) const;
	bool operator!=(const Date& aDate) const;
	bool operator<(const Date& aDate) const;
	bool operator>(const Date& aDate) const;
	bool operator<=(const Date& aDate) const;
	bool operator>=(const Date& aDate) const;

	//io
	friend std::ostream& operator<<(std::ostream& Stream, const Date& aDate);
	friend std::istream& operator>>(std::istream& Stream, Date& aDate);
};

#endif