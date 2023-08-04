/***********************************
 * File Name: ControllerCLI.hpp
 * Function: declare class ControllerCLI
 * Developer(s) & Date: Keqian Tang | 2023-8-1
************************************/

#ifndef __CONTROLLER_CLI_HPP__
#define __CONTROLLER_CLI_HPP__

#include "ControllerBase.hpp"

/*****************************************
Name: ControllerCLI
Function: Commandline version of controller
APIs: Start the program
	  Modify a festival (Modify)
	  Add a festival (Add)
	  Delete a festival (Delete)
	  Get the remaining days to a festival (CountDown)
	  Get the Calendar of a month (GetCalendar)
	  Search festivals in an interval (SearchIn)
	  Exit
Developer & date: Keqian Tang 2023.8.1
******************************************/
class ControllerCLI : public ControllerBase {
public:
	//constructor
	ControllerCLI(const std::string& Path);
	ControllerCLI(const ControllerCLI& Src) = default;

	//destructor
	~ControllerCLI();

	void Start();
	void Modify();
	void Add();
	void Delete();
	void CountDown();
	void GetCalendar();
	void SearchIn();
	void Exit();
	ControllerCLI& operator=(const ControllerCLI& aController) = default;
};

#endif