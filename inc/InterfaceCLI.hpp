/***********************************
 * File Name: InterfaceCLI.hpp
 * Function: declare class InterfaceCLI
 * Developer(s) & Date: Keqian Tang | 2023-8-1
************************************/

#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include "Calendar.hpp"
#include "Date.hpp"
#include "WeekDay.hpp"
#include "FestivalList.hpp"
#include <stdexcept>

/*****************************************
Name: InterfaceCLI
Function: controlling display and IO
APIs: display start menu (StartMenu)
	  select festival type (SelectFestivalType)
	  get the name of a festival (GetFestivalName)
	  show a list of festivals (ShowList)
	  show a calendar (ShowCalendar)
	  select sort by name or date (GetSortMethod)
	  clear the screen (Clear)
	  get a weekday (GetWeekDay)
	  get a date (GetDate)
	  print the message of a exception (OutputExcept)
Developer & date: Keqian Tang 2023.7.12
******************************************/
class InterfaceCLI {
public:
	static void Clear();
	static unsigned int StartMenu();
	static unsigned int SelectFestivalType();
	static void ShowCalendar(const Calendar& Data);
	static void ShowList(const FestivalList& Data);
	static void CountDown(const unsigned int Days);
	static void OutputExcept(std::exception& E);
	static std::string GetFestivalName();
	static Date GetDate();
	static WeekDay GetWeekDay();
	static bool GetSortMethod();
	static void PressEnter();
	
	static int GetNumber(const std::string& Prompt);
};

#endif