#ifndef __DATEINFO_HPP__
#define __DATEINFO_HPP__

class DateInfo {
protected:
	static const unsigned int DAY_Of_MONTH[2][13];
	static const unsigned int MIN_DAY;
	static const unsigned int MIN_MONTH;
	static const unsigned int MAX_MONTH;
	static const unsigned int MIN_YEAR;
	static const unsigned int MAX_YEAR;
};

#endif