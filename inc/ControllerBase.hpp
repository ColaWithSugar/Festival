#ifndef __CONTROLLER_ABSTRACT_BASE_HPP__
#define __CONTROLLER_ABSTRACT_BASE_HPP__

#include <string>
#include "YearDate.hpp"

enum class ReturnVal {
	ADD = 1,
	DELETE,
	SEARCH,
	CALENDAR,
	MODIFY,
	COUNT_DOWN,
	EXIT
};

class ControllerBase : public DateInfo {
protected:
	YearDate m_NowDate;
	const std::string FILE_PATH;
public:
	const YearDate& NowDate;

	ControllerBase(const std::string& Path);
	ControllerBase(const unsigned int Year,
				   const unsigned int Month,
				   const unsigned int Day,
				   const std::string& Path);

	virtual void Start() = 0;
	virtual void Modify() = 0;
	virtual void Add() = 0;
	virtual void Delete() = 0;
	virtual void CountDown() = 0;
	virtual void GetCalendar() = 0;
	virtual void SearchIn() = 0;
	virtual void Exit() = 0;
	static ReturnVal IntToEnum(const unsigned int Data);
};

#endif