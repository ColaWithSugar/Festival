#ifndef __DATEFESTIVAL_HPP__
#define __DATEFESTIVAL_HPP__
#include "festival.hpp"
class DateFestival : public Festival{
private:
	unsigned int m_Day;
	unsigned int m_Month;
	static const unsigned int DayOfMonth[13];
	static const unsigned int MinMonth;
	static const unsigned int MinDay;
	static const unsigned int MaxMonth;

	void SetMonth(unsigned int Month);
	void SetDay(unsigned int Day);
	void SetDate(unsigned int Month, unsigned int Day);
	static bool IsValidDate(unsigned int Month, unsigned int Day);
protected:
	DateFestival(const std::string& Name, unsigned int Month, unsigned int Day);
public:
	const unsigned int& Day;
	const unsigned int& Month;
	static void DelFestival(const std::string& Name);
	static void DelFestival(const char* Name) = delete;
	static const DateFestival& AddFestival(const std::string& Name, unsigned int Month, unsigned int Day);
	static const DateFestival& AddFestival(const char* Name, unsigned int Month, unsigned int Day) = delete;
	static const DateFestival& FindFestival(const std::string& Name);
	static const DateFestival& FindFestival(const char* Name) = delete;
	static const DateFestival& ModifyFestival(const std::string& Name, unsigned int Month, unsigned int Day);
	static const DateFestival& ModifyFestival(const char* Name, unsigned int Month, unsigned int Day) = delete;
};

#endif