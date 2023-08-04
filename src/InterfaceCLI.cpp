#include "InterfaceCLI.hpp"
#include "YearDate.hpp"
#include "WeekDay.hpp"
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>

/*****************************************
Name: StartMenu
Function: display start menu
Parameters: None
Return value: an integer indicating choices.
Developer & date: Keqian Tang 2023.8.2
******************************************/
unsigned int InterfaceCLI::StartMenu() {
	Clear();
	std::cout << "Welcome to the Festival Managing System." << std::endl;
	std::cout << "Please type a number to select mode." << std::endl;
	std::cout << "1) Add a festival." << std::endl;
	std::cout << "2) Delete a festival." << std::endl;
	std::cout << "3) Search in a certain range." << std::endl;
	std::cout << "4) Print a calendar." << std::endl;
	std::cout << "5) Modify a festival." << std::endl;
	std::cout << "6) Get the number of days to a festival." << std::endl;
	std::cout << "7) Exit" << std::endl;
	std::cout << std::endl;
	unsigned int input = GetNumber(">>> ");
	return input;
}

/*****************************************
Name: SelectFestivalType
Function: select the festival type (DateFestival WeekDayFestival)
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
unsigned int InterfaceCLI::SelectFestivalType() {
	std::cout << "Select your festival type." << std::endl;
	std::cout << "1) Date Festival." << std::endl;
	std::cout << "2) Week Day Festival" << std::endl;
	std::cout << "3) Back" << std::endl;
	std::cout << std::endl;
	unsigned int input = GetNumber(">>> ");
	return input;
}

/*****************************************
Name: Clear
Function: clear the screen
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void InterfaceCLI::Clear() {
	system("clear");
}

/*****************************************
Name: ShowCalendar
Function: display a calendar
Parameters: a Calendar
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void InterfaceCLI::ShowCalendar(const Calendar& Data) {
	unsigned int Month = (Data.Month + Data.MAX_MONTH - Data.MIN_MONTH - 1) % Data.MAX_MONTH + Data.MIN_MONTH;
	unsigned int Day = Data.DAYS_OF_MONTH[YearDate::IsLeapYear(Data.Year)][Month] - Data.StartDay + 1;
	std::cout << " SUN"
	          << " MON"
			  << " TUE"
			  << " WED"
			  << " THU"
			  << " FRI"
			  << " SAT"
			  << std::endl;
	
	// print days
	for ( ; ; ) {
		if (Day > Data.DAYS_OF_MONTH[YearDate::IsLeapYear(Data.Year)][Month]) {
			Day = Data.MIN_DAY;
			Month = (Month + Data.MAX_MONTH - Data.MIN_MONTH + 1) % Data.MAX_MONTH + Data.MIN_MONTH;
		}
		if (Month > Data.Month)
			break;
		for (int i = 0; i < 7; ++i) {
			std::cout << std::setw(4) << Day;
			Day++;
			if (Day > Data.DAYS_OF_MONTH[YearDate::IsLeapYear(Data.Year)][Month]) {
				Day = Data.MIN_DAY;
				Month = (Month + Data.MAX_MONTH - Data.MIN_MONTH + 1) % Data.MAX_MONTH + Data.MIN_MONTH;
			}
		} //print a line
		std::cout << std::endl;
	}
	for (auto& n : Data.Festivals) {
		std::cout << n.first << ' ' << n.second << std::endl;
	}
	PressEnter();
}

/*****************************************
Name: ShowList
Function: display a FestivalList
Parameters: a festivalList
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void InterfaceCLI::ShowList(const FestivalList& Data) {
	for (auto& n : Data.Festivals) {
		std::cout << n.first << ' ' << n.second << std::endl;
	}
	PressEnter();
}

/*****************************************
Name: CountDown
Function: display left days.
Parameters: an integer Days
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void InterfaceCLI::CountDown(const unsigned int Days) {
	std::cout << Days << " days left." << std::endl;
	PressEnter();
}

/*****************************************
Name: GetFestivalName
Function: get a name of a festival
Parameters: None
Return value: string name
Developer & date: Keqian Tang 2023.8.2
******************************************/
std::string InterfaceCLI::GetFestivalName() {
	std::cout << "Type the name of the festival." << std::endl;
	std::cout << ">>> ";
	std::string Name;
	std::getline(std::cin, Name);
	return Name;
}

/*****************************************
Name: GetDate
Function: get a Date
Parameters: None
Return value: Date
Developer & date: Keqian Tang 2023.8.2
******************************************/
Date InterfaceCLI::GetDate() {
	std::cout << "Type the month of the festival." << std::endl;
	unsigned int Month = GetNumber(">>> ");
	std::cout << "Type the day of the festival." << std::endl;
	unsigned int Day = GetNumber(">>> ");
	return Date(Month, Day);
}

/*****************************************
Name: GetWeekDay
Function: get a WeekDay
Parameters: None
Return value: WeekDay
Developer & date: Keqian Tang 2023.8.2
******************************************/
WeekDay InterfaceCLI::GetWeekDay() {
	std::cout << "Type the month of the festival." << std::endl;
	unsigned int Month = GetNumber(">>> ");
	std::cout << "Type the week of the festival. (1, 2, 3, 4, -1)" << std::endl;
	int Week = GetNumber(">>> ");
	std::cout << "Type the day of the festival. (MON, TUE, WED, THU, FRI, SAT, SUN)" << std::endl;
	std::cout << ">>> ";
	std::string str_Day;
	std::getline(std::cin, str_Day);
	DateInfo::DayType Day;
	Day = DateInfo::StringToEnum(str_Day);
	return WeekDay(Month, Week, Day);
}

/*****************************************
Name: GetNumber
Function: get a Number (with exception)
Parameters: a prompt
Return value: an integer
Developer & date: Keqian Tang 2023.8.2
******************************************/
int InterfaceCLI::GetNumber(const std::string& Prompt) {
	bool IsNum = true;
	bool IsNeg = false;
	std::cout << Prompt;
	std::string Buf;
	std::getline(std::cin, Buf);
	std::string::iterator itr;
	for (itr = Buf.begin(); itr != Buf.end(); itr++) {
		if (*itr == '-' && itr == Buf.begin() && (itr + 1) != Buf.end()) {
			IsNeg = true;
			continue;
		}
		else if (*itr < '0' || *itr > '9') {
			throw InvalidInput();
		}
	}
	int Res = 0;
	if (IsNeg) {
		itr = Buf.begin() + 1;
	}
	else {
		itr = Buf.begin();
	}
	for (; itr != Buf.end(); itr++) {
		Res *= 10;
		Res += *itr - '0';
	}
	return (IsNeg ? -Res : Res);
}

/*****************************************
Name: GetNumber
Function: Select a sort method (date or name).
Parameters: a prompt
Return value: an integer
Developer & date: Keqian Tang 2023.8.2
******************************************/
bool InterfaceCLI::GetSortMethod() {
	Clear();
	std::cout << "1) Sort by date" << std::endl;
	std::cout << "2) Sort by name" << std::endl;
	unsigned int Choice = GetNumber(">>> ");
	switch(Choice) {
	case 1:
		return false;
	case 2:
		return true;
	default:
		throw InvalidInput();
	}
	Clear();
}

/*****************************************
Name: OutputExcept
Function: output the message of an exception
Parameters: an exception
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void InterfaceCLI::OutputExcept(std::exception& E) {
	Clear();
	std::cout << E.what() << std::endl;
	PressEnter();
}

/*****************************************
Name: PressEnter
Function: PRESS ENTER TO CONTINUE
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void InterfaceCLI::PressEnter() {
	std::cout << std::endl
	          << "PRESS ENTER TO CONTINUE."
			  << std::endl;
	getchar();
	Clear();
}