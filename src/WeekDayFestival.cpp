#include "WeekDayFestival.hpp"
#include "DateInfo.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>

const std::string WeekDayFestival::FILE_NAME = "WeekDayFestival.txt";

/***********************************
 * File Name: DateFestival.cpp
 * Function: define APIs of DateFestival to manipulate festival information.
 * Developer(s) & Date: Keqian Tang | 2023-8-2
************************************/
WeekDayFestival::WeekDayFestival(
	const std::string& Name, unsigned int Month, int Week, DateInfo::DayType Day) :
	Festival::Festival(Name), 
	m_WeekDay(Month, Week, Day), 
	Month(m_WeekDay.Month), 
	Day(m_WeekDay.Day), 
	Week(m_WeekDay.Week),
	r_WeekDay(m_WeekDay) {
	return;
}

/*****************************************
Name: GetType
Function: identify the object.
Parameters: None
Return value: enum FesType representing WeekDayFestival.
Developer & date: Keqian Tang 2023.7.21
******************************************/
WeekDayFestival::FesType WeekDayFestival::GetType() const {
	return WEEKDAY_FES;
}

/*****************************************
Name: IsValidDate
Function: Check wether the WeekDay is valid.
Parameters: Month, Week, Day
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool WeekDayFestival::IsValidWeekDay(unsigned int Month, int Week, DateInfo::DayType Day) {
	if (Month < DateInfo::MIN_MONTH || Month > DateInfo::MAX_MONTH) {
		return false;
	}
	else if (Week != DateInfo::LAST_ONE && (Week < DateInfo::MIN_WEEK || Week > DateInfo::MAX_WEEK)) {
		return false;
	}
	return true;
}

/*****************************************
Name: SetWeekDay
Function: Set the WeekDay of the festival
Parameters: Month, Week and Day
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
void WeekDayFestival::SetWeekDay(unsigned int Month, int Week, DateInfo::DayType Day) {
	if (IsValidWeekDay(Month, Week, Day) == false) {
		throw std::out_of_range("Date is not valid.");
	}
	SetWeek(Week);
	SetMonth(Month);
	SetDay(Day);
}

/*****************************************
Name: SetWeek
Function: Set the Week of the festival
Parameters: Week
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
void WeekDayFestival::SetWeek(int Week) {
	m_WeekDay.SetWeek(Week);
}

/*****************************************
Name: SetMonth
Function: Set the Month of the festival
Parameters: Month
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
void WeekDayFestival::SetMonth(unsigned int Month) {
	m_WeekDay.SetMonth(Month);
}

/*****************************************
Name: SetDay
Function: Set the Day of the festival
Parameters: Day
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
void WeekDayFestival::SetDay(DateInfo::DayType Day) {
	m_WeekDay.SetDay(Day);
}

/*****************************************
Name: AddFestival
Function: add a festival with a date.
Parameters: Name, a date (month and day)
Return value: const WeekDayFestival& (a reference to the new WeekDayFestival)
Developer & date: Keqian Tang 2023.7.21
******************************************/
const WeekDayFestival& WeekDayFestival::AddFestival(
	const std::string& Name, unsigned int Month, int Week, DateInfo::DayType Day) {
	std::for_each(m_All.begin(), m_All.end(), 
		[&](std::shared_ptr<Festival> p) { 
			if(p->Festival::Name == Name) { 
				throw std::invalid_argument("Festival already existed.");
			}
		}
	);
	m_All.push_back(std::shared_ptr<Festival>(
		static_cast<Festival*>(
			new WeekDayFestival(Name, Month, Week, Day))));
	return *static_cast<WeekDayFestival*>(m_All.back().get());
}

/*****************************************
Name: FindFestival
Function: find a festival providing its name
Parameters: Name
Return value: const WeekDayFestival& (a reference to the new WeekDayFestival)
Developer & date: Keqian Tang 2023.7.21
******************************************/
const WeekDayFestival& WeekDayFestival::FindFestival(const std::string& Name) {
	for (auto& n : m_All) {
		if (n->Name == Name) {
			return *static_cast<WeekDayFestival*>(n.get());
		}
	}
	throw std::invalid_argument("Name not found.");
}

/*****************************************
Name: ModifyFestival
Function: Change the information of a festival.
Parameters: Name Month Day
Return value: const WeekDayFestival& (a reference to the new WeekDayFestival)
Developer & date: Keqian Tang 2023.7.21
******************************************/
const WeekDayFestival& WeekDayFestival::ModifyFestival(const std::string& Name, 
													   unsigned int Month, 
													   int Week, 
													   DateInfo::DayType Day) {
	std::vector<std::shared_ptr<Festival> >::iterator itr;
	for (itr = m_All.begin(); itr != m_All.end(); itr++) {
		if ((*itr)->Name == Name) {
			static_cast<WeekDayFestival*>((*itr).get())->SetWeekDay(Month, Week, Day);
			itr--;
			return *static_cast<WeekDayFestival*>((*itr).get());
		}
	}
	throw std::invalid_argument("Name not found.");
}

/*****************************************
Name: ToDate
Function: Transfer a [int]year and a [weekDay] to a [YearDate]
Parameters: Year
Return value: a YearDate decided by WeekDay and Year
Developer & date: Keqian Tang 2023.7.21
******************************************/
YearDate WeekDayFestival::ToDate(const unsigned int Year) const {
	return m_WeekDay.ToDate(Year);
}

/*****************************************
Name: ReadFromFile
Function: read festival information from certain file.
Parameters: Path of the directory
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
void WeekDayFestival::ReadFromFile(const std::string& Path) {
	std::ifstream infile;
	if (*Path.rend() == '/' || *Path.rend() =='\\') {
		infile.open(Path + FILE_NAME, std::ios::in);
	}
	else if (Path.find('\\') != std::string::npos) {
		infile.open(Path + "\\" + FILE_NAME, std::ios::in);
	}
	else if (Path.find('/') !=  std::string::npos) {
		infile.open(Path + "/" + FILE_NAME, std::ios::in);
	}
	else {
		infile.open(Path + "/" + FILE_NAME, std::ios::in);
	}
	if (!infile) {
		return;
	} //get the file name
	while (!infile.eof()) {
		std::string Name;
		unsigned int Month;
		int Week;
		DateInfo::DayType Day;
		std::string str_Day;
		char Temp;
		infile >> Name >> Month  >> Week >> str_Day;
		Day = DateInfo::StringToEnum(str_Day);
		WeekDayFestival::AddFestival(Name, Month, Week, Day);

		infile.get();
		if (infile.peek() == '\n') break;
	} //read from file
}

/*****************************************
Name: SaveToFile
Function: save festival information to certain file.
Parameters: Path of the directory
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
void WeekDayFestival::SaveToFile(const std::string& Path) {
	std::ofstream outfile;
	if (*Path.rend() == '/' || *Path.rend() =='\\') {
		outfile.open(Path + FILE_NAME, std::ios::out | std::ios::trunc);
	}
	else if (Path.find('\\') != std::string::npos) {
		outfile.open(Path + "\\" + FILE_NAME, std::ios::out | std::ios::trunc);
	}
	else if (Path.find('/') !=  std::string::npos) {
		outfile.open(Path + "/" + FILE_NAME, std::ios::out | std::ios::trunc);
	}
	else {
		outfile.open(Path + "/" + FILE_NAME, std::ios::out | std::ios::trunc);
	} //get the file name

	for (auto& n : m_All) {
		if ((*n).GetType() == WEEKDAY_FES) {
			outfile << n->Name << " " << static_cast<WeekDayFestival*>(n.get())->r_WeekDay << std::endl;
		}
	} //save to file
}

