#ifndef __YEARDATE_HPP__
#define __YEARDATE_HPP__

#include "Date.hpp"

class YearDate : public Date {
private:
	unsigned int m_Year;

protected:
	;
public:
	const unsigned int& Year;

	YearDate(const unsigned int Year = MIN_YEAR, 
	         const unsigned int Month = MIN_MONTH, 
			 const unsigned int Day = MIN_DAY);

	YearDate(const YearDate& aYearDate);

	void SetDate(const unsigned int Year, const unsigned int Month, const unsigned int Day);
	void SetYear(const unsigned int Year);
	static bool IsLeapYear(const unsigned int Year);
	bool        IsLeapYear() const;
	static bool IsValidDate(const unsigned int Year, const unsigned int Month, const unsigned int Day);
	bool        IsValidDate() const;
	
	const YearDate& operator=(const YearDate& aYearDate);
	int operator-(const YearDate& aYearDate) const;

	bool operator==(const YearDate& aYearDate) const;
	bool operator!=(const YearDate& aYearDate) const;
	bool operator<(const YearDate& aYearDate) const;
	bool operator>(const YearDate& aYearDate) const;
	bool operator<=(const YearDate& aYearDate) const;
	bool operator>=(const YearDate& aYearDate) const;
	// friend bool operator==(const YearDate& YearDateA, const YearDate& YearDateB);
	// friend bool operator!=(const YearDate& YearDateA, const YearDate& YearDateB);
	// friend bool operator<(const YearDate& YearDateA, const YearDate& YearDateB);
	// friend bool operator>(const YearDate& YearDateA, const YearDate& YearDateB);
	// friend bool operator<=(const YearDate& YearDateA, const YearDate& YearDateB);
	// friend bool operator>=(const YearDate& YearDateA, const YearDate& YearDateB);

	friend std::ostream& operator<<(std::ostream& Stream, const YearDate& aYearDate);
	friend std::istream& operator>>(std::istream& Stream, YearDate& aYearDate);
};

#endif