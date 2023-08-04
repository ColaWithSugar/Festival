/***********************************
 * File Name: DateFestival.cpp
 * Function: define APIs of DateFestival to manipulate festival information.
 * Developer(s) & Date: Keqian Tang | 2023-8-2
************************************/

#include "DateFestival.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>

const std::string DateFestival::FILE_NAME = "DateFestival.txt";

/*****************************************
Name: DateFestival
Function: constructor of DateFestival
Parameters: name of the festival, month, day
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
DateFestival::DateFestival(const std::string& Name, unsigned int Month, unsigned int Day) 
	: Festival::Festival(Name), m_Date(Month, Day), Month(m_Date.Month), Day(m_Date.Day), r_Date(m_Date) {
	return;
}

/*****************************************
Name: GetType
Function: identify the object.
Parameters: None
Return value: enum FesType representing DateFestival.
Developer & date: Keqian Tang 2023.7.21
******************************************/
DateFestival::FesType DateFestival::GetType() const {
	return DATE_FES;
}

/*****************************************
Name: ToDate
Function: Transfer a [int]year and a [Date] to a [YearDate]
Parameters: Year
Return value: a YearDate consisting of m_Date and Year
Developer & date: Keqian Tang 2023.7.21
******************************************/
YearDate DateFestival::ToDate(const unsigned int Year) const {
	return YearDate(Year, m_Date.Month, m_Date.Day);
}

/*****************************************
Name: IsValidDate
Function: Check wether the date is valid.
Parameters: Month, Day
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool DateFestival::IsValidDate(const unsigned int Month, const unsigned int Day) {
	return Date::IsValidDate(Month, Day, false);
}

/*****************************************
Name: IsValidDate
Function: Check wether the date is valid.
Parameters: None
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool DateFestival::IsValidDate() {
	return m_Date.IsValidDate(false);
}

/*****************************************
Name: SetMonth
Function: Set the month of the festival
Parameters: Month
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline void DateFestival::SetMonth(const unsigned int Month) {
	m_Date.SetMonth(Month);
}

/*****************************************
Name: SetDay
Function: Set the day of the festival
Parameters: Day
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline void DateFestival::SetDay(const unsigned int Day) {
	m_Date.SetDay(Day);
}

/*****************************************
Name: SetDate
Function: Set the date of the festival
Parameters: Month and Day
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
inline void DateFestival::SetDate(const unsigned int Month, const unsigned int Day) {
	m_Date.SetDate(Month, Day);
}

/*****************************************
Name: AddFestival
Function: add a festival with a date.
Parameters: Name, a date (month and day)
Return value: const DateFestival& (a reference to the new DateFestival)
Developer & date: Keqian Tang 2023.7.21
******************************************/
const DateFestival& DateFestival::AddFestival(
	const std::string& Name, unsigned int Month, unsigned Day) {
	if (IsValidDate(Month, Day) == false) {
		throw InvalidDate();
	}
	std::for_each(m_All.begin(), m_All.end(), 
		[&](std::shared_ptr<Festival> p) { 
			if(p->Festival::Name == Name) { 
				throw FestivalExists();
			}
		}
	);
	m_All.push_back(std::shared_ptr<Festival>(
		static_cast<Festival*>(
			new DateFestival(Name, Month, Day))));
	return *static_cast<DateFestival*>(m_All.back().get());
}

/*****************************************
Name: FindFestival
Function: find a festival providing its name
Parameters: Name
Return value: const DateFestival& (a reference to the new DateFestival)
Developer & date: Keqian Tang 2023.7.21
******************************************/
const DateFestival& DateFestival::FindFestival(const std::string& Name) {
	for (auto& n : m_All) {
		if (n->Name == Name) {
			return *static_cast<DateFestival*>(n.get());
		}
	}
	throw NameNotFound();
}

/*****************************************
Name: ModifyFestival
Function: Change the information of a festival.
Parameters: Name Month Day
Return value: const DateFestival& (a reference to the new DateFestival)
Developer & date: Keqian Tang 2023.7.21
******************************************/
const DateFestival& DateFestival::ModifyFestival(const std::string& Name, unsigned int Month, unsigned int Day) {
	std::vector<std::shared_ptr<Festival> >::iterator itr;
	for (itr = m_All.begin(); itr != m_All.end(); itr++) {
		if ((*itr)->Name == Name) {
			static_cast<DateFestival*>((*itr).get())->SetDate(Month, Day);
			return *static_cast<DateFestival*>((*itr).get());
		}
	}
	throw NameNotFound();
}

/*****************************************
Name: ReadFromFile
Function: read festival information from certain file.
Parameters: Path of the directory
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
void DateFestival::ReadFromFile(const std::string& Path) {
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
	}
	while (!infile.eof()) {
		std::string Name;
		unsigned int Month;
		unsigned int Day;
		char Temp;
		infile >> Name >> Month >> Temp >> Day;
		DateFestival::AddFestival(Name, Month, Day);

		infile.get();
		if (infile.peek() == '\n') break;
	}
}

/*****************************************
Name: SaveToFile
Function: save festival information to certain file.
Parameters: Path of the directory
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
void DateFestival::SaveToFile(const std::string& Path) {
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
	}
	for (auto& n : m_All) {
		if ((*n).GetType() == DATE_FES) {
			outfile << n->Name << " " << static_cast<DateFestival*>(n.get())->r_Date << std::endl;
		}
	}
}