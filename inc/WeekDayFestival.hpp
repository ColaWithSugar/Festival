/***********************************
 * File Name: WeekDayFestival.hpp
 * Function: declare class WeekDayfestival
 * Developer(s) & Date: Keqian Tang | 2023-8-1
************************************/


#ifndef __WEEKDAYFESTIVAL_HPP__
#define __WEEKDAYFESTIVAL_HPP__
#include "Festival.hpp"
#include "WeekDay.hpp"

/*****************************************
Name: WeekDayFestival
Function: festival with weekday.
APIs: Add a festival (AddFestival).
      Find a festival (FindFestival).
	  Modify a festival (ModifyFestival)
      Generate a the date of a festival in a year (ToDate)
	  read festivals from file (ReadFromFile)
	  save festivals to file (SaveToFile)
Developer & date: Keqian Tang 2023.7.21
******************************************/
class WeekDayFestival : public Festival{
private:
	WeekDay m_WeekDay; //WeekDay of the festival

	void SetMonth(const unsigned int Month);
	void SetWeek(const int Week);
	void SetDay(DateInfo::DayType Day);
	void SetWeekDay(const unsigned int Month, const int Week, DateInfo::DayType Day);

	static bool IsValidWeekDay(unsigned int Month, int Week, DateInfo::DayType Day);

protected:
	//contructor
	WeekDayFestival(const std::string& Name, unsigned int Month, int Week, DateInfo::DayType Day);
	WeekDayFestival(const WeekDay& Src) = delete;

public:
	const unsigned int& Month;
	const int& Week;
	const DateInfo::DayType& Day;
	const WeekDay& r_WeekDay;

	static const std::string FILE_NAME; //file path to store festivals

	static void ReadFromFile(const std::string& Path);
	static void SaveToFile(const std::string& Path);

	FesType GetType() const;
	YearDate ToDate(const unsigned int Year) const;

	static const WeekDayFestival& AddFestival(
		const std::string& Name, unsigned int Month, int Week, DateInfo::DayType Day);
	static const WeekDayFestival& AddFestival(
		const char* Name, unsigned int Month, int Week, DateInfo::DayType Day) = delete;

	static const WeekDayFestival& FindFestival(const std::string& Name);
	static const WeekDayFestival& FindFestival(const char* Name) = delete;
	static const WeekDayFestival& ModifyFestival(const std::string& Name, 
											     const unsigned int Month, 
												 int Week, 
												 DateInfo::DayType Day);
	static const WeekDayFestival& ModifyFestival(const char* Name, 
	                                             const unsigned int Month, 
												 int Week, 
												 DateInfo::DayType Day) = delete;

	WeekDayFestival& operator=(const WeekDayFestival& aFes) = delete;

	//IO
	friend bool operator<<(std::ostream Stream, const WeekDayFestival& aFes);
	friend bool operator>>(std::istream Stream, WeekDayFestival& aFes);
};

#endif