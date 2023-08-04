#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include "Calendar.hpp"
#include "Date.hpp"
#include "WeekDay.hpp"
#include "FestivalList.hpp"
#include <stdexcept>

class InterfaceCLI {
public:
	static unsigned int StartMenu();
	static unsigned int SelectFestivalType();
	static std::string GetFestivalName();
	static void ShowCalendar(const Calendar& Data);
	static void ShowList(const FestivalList& Data);
	static void CountDown(const unsigned int Days);
	static void Clear();
	static Date GetDate();
	static WeekDay GetWeekDay();
	static bool GetSortMethod();
	static void OutputExcept(std::exception& E);
	static int GetNumber(const std::string& Prompt);
};

#endif