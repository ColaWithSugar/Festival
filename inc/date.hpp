#ifndef __DATE_HPP__
#define __DATE_HPP__

#include "dateinfo.hpp"

class Date : protected DateInfo{
private:
	unsigned int m_Month;
	unsigned int m_Day;

protected:
	Date(const unsigned int Month, const unsigned int Day);

public:
	const unsigned int& Month;
	const unsigned int& Day;
	void SetMonth(const unsigned int Day);
	void SetDay(const unsigned int Day);
	void SetDate(const unsigned int Month, const unsigned int Day);
	static bool IsValidDate(const unsigned int Month, const unsigned int Day);
	bool IsValidDate() const;
};

#endif