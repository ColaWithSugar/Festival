#ifndef __WEEKDAYFESTIVAL_HPP__
#define __WEEKDAYFESTIVAL_HPP__
#include "festival.hpp"
#include "weekday.hpp"
class WeekDayFestival : public Festival{
private:
	WeekDay m_WeekDay;

	void SetMonth(const unsigned int Month);
	void SetWeek(const unsigned int Week);
	void SetDay(const unsigned int Day);
	void SetWeekDay(const unsigned int Month, const unsigned int Week, const unsigned int Day);
	static bool IsValidWeekDay(unsigned int Month, unsigned int Week, unsigned int Day);
protected:
	WeekDayFestival(const std::string& Name, unsigned int Month, unsigned int Week, unsigned int Day);
public:
	const unsigned int& Month;
	const unsigned int& Week;
	const unsigned int& Day;

	static void DelFestival(const std::string& Name);
	static void DelFestival(const char* Name) = delete;

	FesType GetType() const;
	YearDate ToDate(const unsigned int Year) const;

	static const WeekDayFestival& AddFestival(
		const std::string& Name, unsigned int Month, unsigned int Week, unsigned int Day);
	static const WeekDayFestival& AddFestival(
		const char* Name, unsigned int Month, unsigned int Week, unsigned int Day) = delete;

	static const WeekDayFestival& FindFestival(const std::string& Name);
	static const WeekDayFestival& FindFestival(const char* Name) = delete;
	static const WeekDayFestival& ModifyFestival(const std::string& Name, unsigned int Month, unsigned int Week, unsigned int Day);
	static const WeekDayFestival& ModifyFestival(const char* Name, unsigned int Month, unsigned int Week, unsigned int Day) = delete;
};

#endif