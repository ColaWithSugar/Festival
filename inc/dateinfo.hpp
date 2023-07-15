#ifndef __DATEINFO_HPP__
#define __DATEINFO_HPP__

class DateInfo {
protected:
	static const unsigned int DayOfMonth[2][13];
	static const unsigned int MinDay;
	static const unsigned int MinMonth;
	static const unsigned int MaxMonth;
	static const unsigned int MinYear;
	static const unsigned int MaxYear;
};

#endif