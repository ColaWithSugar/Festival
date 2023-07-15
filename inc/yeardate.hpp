#ifndef __YEARDATE_HPP__
#define __YEARDATE_HPP__

#include "date.hpp"

class YearDate : public Date {
private:
	unsigned int m_Year;

protected:
	YearDate(const unsigned int Year, const unsigned int Month, const unsigned int Day);

public:
	const unsigned int& Year;
	void SetDate(const unsigned int Year, const unsigned int Month, const unsigned int Day);
	void SetYear(const unsigned int Year);
	static bool IsValidDate(const unsigned int Year, const unsigned int Month, const unsigned int Day);
	bool IsValidDate() const;
};

#endif