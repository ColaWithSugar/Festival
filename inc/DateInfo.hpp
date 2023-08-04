#ifndef __DATEINFO_HPP__
#define __DATEINFO_HPP__

#include <stdexcept>

class DateInfo {
public:
	static const unsigned int DAYS_OF_MONTH[2][13];
	static const unsigned int MIN_DAY;
	static const unsigned int MIN_WEEK;
	static const unsigned int MAX_WEEK;
	static const unsigned int MIN_MONTH;
	static const unsigned int MAX_MONTH;
	static const unsigned int MIN_YEAR;
	static const unsigned int MAX_YEAR;
	static const unsigned int DAYS_OF_WEEK;
	static const int LAST_ONE;
	static const unsigned int LEAP;
	static const unsigned int COMMON;
	static const unsigned int DAYS_OF_YEAR[2];
	enum class DayType{
		SUN = 0,
		MON = 1,
		TUE = 2,
		WED = 3,
		THU = 4,
		FRI = 5,
		SAT = 6
	};
	static const unsigned int START_DAY_TYPE;

	static DayType StringToEnum(const std::string& Str);
	static std::string EnumToString(const DayType Day);
};

#endif