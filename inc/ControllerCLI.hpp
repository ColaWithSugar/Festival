#ifndef __CONTROLLER_CLI_HPP__
#define __CONTROLLER_CLI_HPP__

#include "ControllerBase.hpp"

class ControllerCLI : public ControllerBase {
public:
	ControllerCLI(const std::string& Path);
	void Start();
	void Modify();
	void Add();
	void Delete();
	void CountDown();
	void GetCalendar();
	void SearchIn();
	void Exit();
	~ControllerCLI();
};

#endif