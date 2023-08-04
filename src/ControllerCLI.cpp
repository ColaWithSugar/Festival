/***********************************
 * File Name: ControllerCLI.cpp
 * Function: define APIs of the commandline controller.
 * Developer(s) & Date: Keqian Tang | 2023-8-2
************************************/


#include "ControllerCLI.hpp"
#include "DateFestival.hpp"
#include "WeekDayFestival.hpp"
#include "InterfaceCLI.hpp"

/*****************************************
Name: ControllerCLI
Function: constructor of ControllerCLI
Parameters: Path of a directory
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
ControllerCLI::ControllerCLI(const std::string& Path) : ControllerBase(Path) { }

/*****************************************
Name: ~ControllerCLI
Function: destructor of ControllerCLI, save data to file automatically
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
ControllerCLI::~ControllerCLI() {
	DateFestival::SaveToFile(FILE_PATH);
	WeekDayFestival::SaveToFile(FILE_PATH);
}

/*****************************************
Name: Start
Function: Start the program
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void ControllerCLI::Start() {
	try {
		DateFestival::ReadFromFile(FILE_PATH);
		WeekDayFestival::ReadFromFile(FILE_PATH);
	}
	catch (std::exception E) {
		std::cout << "FILE ERROR" << std::endl;
	}
	for (bool InfLoop = true; InfLoop;) {
		try {
			ReturnVal Val;
			Val = IntToEnum(InterfaceCLI::StartMenu());
			InterfaceCLI::Clear();
			switch (Val) {
			case ReturnVal::ADD:
				Add();
				break;
			case ReturnVal::DELETE:
				Delete();
				break;
			case ReturnVal::CALENDAR:
				GetCalendar();
				break;
			case ReturnVal::SEARCH:
				SearchIn();
				break;
			case ReturnVal::MODIFY:
				Modify();
				break;
			case ReturnVal::COUNT_DOWN:
				CountDown();
				break;
			case ReturnVal::EXIT:
				Exit();
				return;
			}
		}
		catch (NameNotFound E1) {
			InterfaceCLI::OutputExcept(E1);
			continue;
		}
		catch (InvalidDate E2) {
			InterfaceCLI::OutputExcept(E2);
			continue;
		}
		catch (InvalidYear E3) {
			InterfaceCLI::OutputExcept(E3);
			continue;
		}
		catch (InvalidMonth E4) {
			InterfaceCLI::OutputExcept(E4);
			continue;
		}
		catch (InvalidWeek E5) {
			InterfaceCLI::OutputExcept(E5);
			continue;
		}
		catch (InvalidDay E6) {
			InterfaceCLI::OutputExcept(E6);
			continue;
		}
		catch (DateNotFound E7) {
			InterfaceCLI::OutputExcept(E7);
			continue;
		}
		catch (NoMatchingValues E8) {
			InterfaceCLI::OutputExcept(E8);
			continue;
		}
		catch (FestivalExists E9) {
			InterfaceCLI::OutputExcept(E9);
			continue;
		}
		catch (InvalidInput E10) {
			InterfaceCLI::OutputExcept(E10);
			continue;
		}
	}
}

/*****************************************
Name: Modify
Function: modify a festival
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void ControllerCLI::Modify() {
	InterfaceCLI::Clear();
	std::string Name;
	Name = InterfaceCLI::GetFestivalName();
	const Festival& t_Fes = Festival::FindFestival(Name);
	Festival::FesType Type = t_Fes.GetType();
	if (Type == Festival::FesType::DATE_FES) {
		Date t_Date = InterfaceCLI::GetDate();
		DateFestival::ModifyFestival(Name, t_Date.Month, t_Date.Day);
	}
	if (Type == Festival::FesType::WEEKDAY_FES) {
		WeekDay t_WeekDay = InterfaceCLI::GetWeekDay();
		WeekDayFestival::ModifyFestival(Name, t_WeekDay.Month, t_WeekDay.Week, t_WeekDay.Day);
	}
	InterfaceCLI::Clear();
}

/*****************************************
Name: Add
Function: add a festival
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void ControllerCLI::Add() {
	InterfaceCLI::Clear();

	unsigned int Choice;
	Choice = InterfaceCLI::SelectFestivalType();
	InterfaceCLI::Clear();

	if (Choice == 1) {
		std::string Name = InterfaceCLI::GetFestivalName();
		Date FesDate = InterfaceCLI::GetDate();
		DateFestival::AddFestival(Name, FesDate.Month, FesDate.Day);
	}
	if (Choice == 2) {
		std::string Name = InterfaceCLI::GetFestivalName();
		WeekDay FesWeekDay = InterfaceCLI::GetWeekDay();
		WeekDayFestival::AddFestival(Name, FesWeekDay.Month, FesWeekDay.Week, FesWeekDay.Day);
	}
	InterfaceCLI::Clear();
}

/*****************************************
Name: Delete
Function: Delete a festival
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void ControllerCLI::Delete() {
	InterfaceCLI::Clear();
	std::string Name = InterfaceCLI::GetFestivalName();
	Festival::DelFestival(Name);
	InterfaceCLI::Clear();
}

/*****************************************
Name: Delete
Function: Delete a festival
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void ControllerCLI::CountDown() {
	InterfaceCLI::Clear();
	std::string Name = InterfaceCLI::GetFestivalName();
	const DateFestival& Fes = DateFestival::FindFestival(Name);
	unsigned int t_Year = NowDate.Year;
	while (!YearDate::IsValidDate(t_Year, Fes.Month, Fes.Day)
	       || YearDate(t_Year, Fes.Month, Fes.Day) < NowDate) {
		t_Year++;
	}
	YearDate FesDate(t_Year, Fes.Month, Fes.Day);
	int Days = (FesDate - NowDate);
	InterfaceCLI::CountDown(Days);
	InterfaceCLI::Clear();
}

/*****************************************
Name: GetCalendar
Function: Get the calendar of a month
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void ControllerCLI::GetCalendar() {
	InterfaceCLI::Clear();
	unsigned int Year;
	unsigned int Month;
	Year = InterfaceCLI::GetNumber("Year: ");
	Month = InterfaceCLI::GetNumber("Month: ");
	Calendar Cal(Year, Month);
	Cal.LoadFestivals(Festival::All);
	InterfaceCLI::ShowCalendar(Cal);
	InterfaceCLI::Clear();
}

/*****************************************
Name: SearchIn
Function: Search festivals in an interval.
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void ControllerCLI::SearchIn() {
	unsigned int Year1 = InterfaceCLI::GetNumber("Year1:");
	unsigned int Month1 = InterfaceCLI::GetNumber("Month1:");
	unsigned int Day1 = InterfaceCLI::GetNumber("Day1:");
	unsigned int Year2 = InterfaceCLI::GetNumber("Year2:");
	unsigned int Month2 = InterfaceCLI::GetNumber("Month2:");
	unsigned int Day2 = InterfaceCLI::GetNumber("Day2:");
	bool ByName = InterfaceCLI::GetSortMethod();
	FestivalList List;
	List.SearchIn(YearDate(Year1, Month1, Day1),
			      YearDate(Year2, Month2, Day2),
				  Festival::All);
	if(ByName) {
		List.SortByName();
	}
	InterfaceCLI::ShowList(List);
}

/*****************************************
Name: Exit
Function: Exit
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void ControllerCLI::Exit() {
	std::cout << "Saved to file" << std::endl;
}