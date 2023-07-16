#ifndef __DATE_HPP__
#define __DATE_HPP__

#include <iostream>
#include <stdexcept>
#include "dateinfo.hpp"

class Date : protected DateInfo{
private:
	unsigned int m_Month;
	unsigned int m_Day;

protected:
	;
public:
	const unsigned int& Month;
	const unsigned int& Day;

	Date(const unsigned int Month, const unsigned int Day);

	void SetMonth(const unsigned int Day);
	void SetDay(const unsigned int Day);
	void SetDate(const unsigned int Month, const unsigned int Day, const bool Leap = true);

	static bool IsValidDate(const unsigned int Month, const unsigned int Day, const bool Leap = true);
	bool        IsValidDate(const bool Leap = true) const;

	bool        operator==(const Date& aDate) const;
	bool        operator!=(const Date& aDate) const;
	bool        operator<(const Date& aDate) const;
	bool        operator>(const Date& aDate) const;
	bool        operator<=(const Date& aDate) const;
	bool        operator>=(const Date& aDate) const;
	// friend bool operator==(const Date& DateA, const Date& DateB);
	// friend bool operator!=(const Date& DateA, const Date& DateB);
	// friend bool operator<(const Date& DateA, const Date& DateB);
	// friend bool operator>(const Date& DateA, const Date& DateB);
	// friend bool operator<=(const Date& DateA, const Date& DateB);
	// friend bool operator>=(const Date& DateA, const Date& DateB);
	

	friend std::ostream& operator<<(std::ostream& Stream, const Date& aDate);
	friend std::istream& operator<<(std::istream& Stream, const Date& aDate);
};

#endif