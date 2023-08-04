/***********************************
 * File Name: ControllerBase.hpp
 * Function: declare class ControllerBase
 * Developer(s) & Date: Keqian Tang | 2023-8-1
************************************/

#ifndef __CONTROLLER_ABSTRACT_BASE_HPP__
#define __CONTROLLER_ABSTRACT_BASE_HPP__

#include <string>
#include "YearDate.hpp"

/*****************************************
Name: ReturnVal
Function: define the return values of controller
Developer & date: Keqian Tang 2023.8.1
******************************************/
enum class ReturnVal {
	ADD = 1,
	DELETE,
	SEARCH,
	CALENDAR,
	MODIFY,
	COUNT_DOWN,
	EXIT
};

/*****************************************
Name: ControllerBase
Function: abstract base of controller
APIs: Start the program
	  Modify a festival (Modify)
	  Add a festival (Add)
	  Delete a festival (Delete)
	  Get the remaining days to a festival (CountDown)
	  Get the Calendar of a month (GetCalendar)
	  Search festivals in an interval (SearchIn)
	  Transfer int to ReturnVal type (IntToEnum)
	  Exit
Developer & date: Keqian Tang 2023.8.1
******************************************/
class ControllerBase : public DateInfo {
protected:
	YearDate m_NowDate;           //Date of today
	const std::string FILE_PATH;  //Path of the directory that files are stored in
public:
	const YearDate& NowDate;
	
	//constructors
	ControllerBase(const std::string& Path);
	ControllerBase(const unsigned int Year,
				   const unsigned int Month,
				   const unsigned int Day,
				   const std::string& Path);
	ControllerBase(const ControllerBase& Controller) = delete;

	virtual void Start() = 0;
	virtual void Modify() = 0;
	virtual void Add() = 0;
	virtual void Delete() = 0;
	virtual void CountDown() = 0;
	virtual void GetCalendar() = 0;
	virtual void SearchIn() = 0;
	virtual void Exit() = 0;
	ControllerBase& operator=(const ControllerBase& aController) = default;
	static ReturnVal IntToEnum(const unsigned int Data);
};

#endif