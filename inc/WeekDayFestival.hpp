#ifndef __WEEKDAYFESTIVAL_HPP__
#define __WEEKDAYFESTIVAL_HPP__
#include "Festival.hpp"
#include "WeekDay.hpp"
class WeekDayFestival : public Festival{
private:
	WeekDay m_WeekDay;

	void SetMonth(const unsigned int Month);
	void SetWeek(const int Week);
	void SetDay(DateInfo::DayType Day);
	void SetWeekDay(const unsigned int Month, const int Week, DateInfo::DayType Day);
	static bool IsValidWeekDay(unsigned int Month, int Week, DateInfo::DayType Day);
protected:
	WeekDayFestival(const std::string& Name, unsigned int Month, int Week, DateInfo::DayType Day);
public:
	const unsigned int& Month;
	const int& Week;
	const DateInfo::DayType& Day;
	const WeekDay& r_WeekDay;

	static const std::string FILE_NAME;

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
};

#endif