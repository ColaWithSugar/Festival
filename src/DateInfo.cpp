/***********************************
 * File Name: DateInfo.cpp
 * Function: define constant values and APIs of DateInfo.
 * Developer(s) & Date: Keqian Tang | 2023-8-1
************************************/

#include "DateInfo.hpp"

const unsigned int DateInfo::MIN_YEAR = 1900;
const unsigned int DateInfo::MAX_YEAR = 9999;

const unsigned int DateInfo::MIN_MONTH = 1;
const unsigned int DateInfo::MAX_MONTH = 12;

const unsigned int DateInfo::MIN_DAY = 1;
const unsigned int DateInfo::DAYS_OF_MONTH[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

const unsigned int DateInfo::MIN_WEEK = 1;
const unsigned int DateInfo::MAX_WEEK = 4;
const unsigned int DateInfo::DAYS_OF_WEEK = 7;

const int DateInfo::LAST_ONE = -1;

const unsigned int DateInfo::COMMON = 0;
const unsigned int DateInfo::LEAP = 1;
const unsigned int DateInfo::START_DAY_TYPE = 1;

const unsigned int DateInfo::DAYS_OF_YEAR[2] = { 365, 366 };

/*****************************************
Name: StringToEnum
Function: Transfer string to DayType
Parameters: a string (MON ...)
Return value: a DayType
Developer & date: Keqian Tang 2023.7.21
******************************************/
DateInfo::DayType DateInfo::StringToEnum(const std::string& Str) {
	if (Str == "SUN")
		return DateInfo::DayType::SUN;
	else if (Str == "MON")
		return DateInfo::DayType::MON;
	else if (Str == "TUE")
		return DateInfo::DayType::TUE;
	else if (Str == "WED")
		return DateInfo::DayType::WED;
	else if (Str == "THU")
		return DateInfo::DayType::THU;
	else if (Str == "FRI")
		return DateInfo::DayType::FRI;
	else if (Str == "SAT")
		return DateInfo::DayType::SAT;
	else
		throw std::invalid_argument("Cannot find matching value.");
}

/*****************************************
Name: StringToEnum
Function: Transfer string to DayType
Parameters: a DayType
Return value: a string (MON ...)
Developer & date: Keqian Tang 2023.7.21
******************************************/
std::string DateInfo::EnumToString(const DateInfo::DayType Day) {
	switch (Day) {
	case DateInfo::DayType::SUN:
		return "SUN";
	case DateInfo::DayType::MON:
		return "MON";
	case DateInfo::DayType::TUE:
		return "TUE";
	case DateInfo::DayType::WED:
		return "WED";
	case DateInfo::DayType::THU:
		return "THU";
	case DateInfo::DayType::FRI:
		return "FRI";
	case DateInfo::DayType::SAT:
		return "SAT";
	default:
		throw std::invalid_argument("Invalid Day.");
	}
}

