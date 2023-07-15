#ifndef __WEEKDAYFESTIVAL_HPP__
#define __WEEKDAYFESTIVAL_HPP__
#include "festival.hpp"
class WeekDayFestival : public Festival{
private:
	unsigned int m_Month;
	unsigned int m_Week;
	unsigned int m_Day;
	static const unsigned int DayOfMonth[13];
	static const unsigned int MinWeek;
	static const unsigned int MinDay;
	static const unsigned int MaxMonth;
	static const unsigned int MinMonth;
	static const unsigned int DayOfWeek;

	void SetWeek(unsigned int Week);
	void SetMonth(unsigned int Month);
	void SetWeekDay(unsigned int Month, unsigned int Week, unsigned int Day);
	void SetDay(unsigned int Day);
	static bool IsValidWeekDay(unsigned int Month, unsigned int Week, unsigned int Day);
protected:
	WeekDayFestival(const std::string& Name, unsigned int Month, unsigned int Week, unsigned int Day);
public:
	const unsigned int& Month;
	const unsigned int& Week;
	const unsigned int& Day;
	static void DelFestival(const std::string& Name);
	static void DelFestival(const char* Name) = delete;
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