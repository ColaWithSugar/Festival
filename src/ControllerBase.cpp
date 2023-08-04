/***********************************
 * File Name: ControllerBase.cpp
 * Modules: define APIs of the abstract base of controller.
 * Developer(s) & Date: Keqian Tang | 2023-8-2
************************************/

#include "ControllerBase.hpp"
#include "Exceptions.hpp"
#include <ctime>
#include <iostream>

/*****************************************
Name: ControllerBase
Function: constructor of ControllerBase. Get the current time.
Parameters: Path to the target directory
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
ControllerBase::ControllerBase(const std::string& Path) : NowDate(m_NowDate), m_NowDate(), FILE_PATH(Path){
	time_t Now = time(0);
	tm *Gmtm = gmtime(&Now);
	m_NowDate.SetDate(Gmtm->tm_year + MIN_YEAR, Gmtm->tm_mon + MIN_MONTH, Gmtm->tm_mday);
}

/*****************************************
Name: ControllerBase
Function: constructor of ControllerBase. Set the time.
Parameters: a date (year, month, day), Path to the target directory
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
ControllerBase::ControllerBase(const unsigned int Year,
				   			   const unsigned int Month,
				   			   const unsigned int Day,
							   const std::string& Path) : NowDate(m_NowDate), m_NowDate(), FILE_PATH(Path) {
	m_NowDate.SetDate(Year, Month, Day);
}

/*****************************************
Name: IntToEnum
Function: transfer [int] to [ReturnVal]
Parameters: a integer from 1 to 7
Return value: enum ReturnVal
Developer & date: Keqian Tang 2023.8.2
******************************************/
ReturnVal ControllerBase::IntToEnum(const unsigned int Data) {
	switch(Data) {
	case 1:
		return ReturnVal::ADD;
	case 2:
		return ReturnVal::DELETE;
	case 3:
		return ReturnVal::SEARCH;
	case 4:
		return ReturnVal::CALENDAR;
	case 5:
		return ReturnVal::MODIFY;
	case 6:
		return ReturnVal::COUNT_DOWN;
	case 7:
		return ReturnVal::EXIT;
	default:
		throw NoMatchingValues();
	}
}