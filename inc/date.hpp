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
	void SetDate(const unsigned int Month, const unsigned int Day, const bool Leap);

	static bool IsValidDate(const unsigned int Month, const unsigned int Day, const bool Leap);
	bool        IsValidDate(const bool Leap) const;

	bool        operator==(const Date& aDate) const;
	friend bool operator==(const Date& DateA, const Date& DateB);
	bool        operator!=(const Date& aDate) const;
	friend bool operator!=(const Date& DateA, const Date& DateB);
	bool        operator<(const Date& aDate) const;
	friend bool operator<(const Date& DateA, const Date& DateB);
	bool        operator>(const Date& aDate) const;
	friend bool operator>(const Date& DateA, const Date& DateB);
	bool        operator<=(const Date& aDate) const;
	friend bool operator<=(const Date& DateA, const Date& DateB);
	bool        operator>=(const Date& aDate) const;
	friend bool operator>=(const Date& DateA, const Date& DateB);
	

	friend std::ostream& operator<<(std::ostream& Stream, const Date& aDate);
	friend std::istream& operator<<(std::istream& Stream, const Date& aDate);
};

class InvalidDate : std::invalid_argument {
public:
	InvalidDate();
};

#endif