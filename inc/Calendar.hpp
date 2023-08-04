#ifndef __CALENDAR_HPP__
#define __CALENDAR_HPP__

#include "DateInfo.hpp"
#include "YearDate.hpp"
#include "Festival.hpp"
#include <vector>
#include <utility>

class Calendar : public DateInfo{
private:
	unsigned int m_Month;
	unsigned int m_Year;
	unsigned int m_StartDay;
	unsigned int m_IsLeap;
protected:
	std::vector<std::pair<std::string, YearDate>> m_Festivals;
public:
	const unsigned int& Month;
	const unsigned int& Year;
	const unsigned int& StartDay;
	const unsigned int& IsLeap;
	std::vector<std::pair<std::string, YearDate>>& Festivals;
	Calendar(const unsigned int Year, const unsigned int Month);
	~Calendar();
	void Set(const unsigned int Year, const unsigned int Month);
	void LoadFestivals(const std::vector<std::shared_ptr<Festival>>& Data);
};

#endif