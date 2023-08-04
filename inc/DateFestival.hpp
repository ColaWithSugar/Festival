/***********************************
 * File Name: DateFestival.hpp
 * Function: declare class DateFestival
 * Developer(s) & Date: Keqian Tang | 2023-7-21
************************************/

#ifndef __DATEFESTIVAL_HPP__
#define __DATEFESTIVAL_HPP__

#include "Festival.hpp"
#include "Date.hpp"
#include "YearDate.hpp"
#include <iostream>

/*****************************************
Name: DateFestival
Function: festival with date.
APIs: Add a festival (AddFestival).
      Find a festival (FindFestival).
	  Modify a festival (ModifyFestival)
      Generate a the date of a festival in a year (ToDate)
	  read festivals from file (ReadFromFile)
	  save festivals to file (SaveToFile)
Developer & date: Keqian Tang 2023.7.21
******************************************/
class DateFestival : public Festival{
private:
	Date m_Date;           //date of the festival
	static bool IsValidDate(unsigned int Month, unsigned int Day);
	bool IsValidDate();

protected:
	void SetMonth(const unsigned int Month);
	void SetDay(const unsigned int Day);
	void SetDate(const unsigned int Month, unsigned int Day);
	DateFestival(const std::string& Name, unsigned int Month, unsigned int Day);

public:
	const unsigned int& Day;
	const unsigned int& Month;
	const Date& r_Date;
	static const std::string FILE_NAME; //file to store festivals

	FesType GetType() const;
	YearDate ToDate(const unsigned int Year) const;

	static void ReadFromFile(const std::string& Path);
	static void SaveToFile(const std::string& Path);
	
	static const DateFestival& AddFestival(const std::string& Name, unsigned int Month, unsigned int Day);
	static const DateFestival& AddFestival(const char* Name, unsigned int Month, unsigned int Day) = delete;
	
	static const DateFestival& FindFestival(const std::string& Name);
	static const DateFestival& FindFestival(const char* Name) = delete;
	
	static const DateFestival& ModifyFestival(const std::string& Name, unsigned int Month, unsigned int Day);
	static const DateFestival& ModifyFestival(const char* Name, unsigned int Month, unsigned int Day) = delete;
	
	DateFestival& operator=(const DateFestival& aFes) = delete;

	//IO
	friend bool operator<<(std::ostream Stream, const DateFestival& aFes);
	friend bool operator>>(std::istream Stream, DateFestival& aFes);
};

#endif