#include "dateinfo.hpp"

const unsigned int DateInfo::MIN_YEAR = 1900;
const unsigned int DateInfo::MAX_YEAR = 9999;

const unsigned int DateInfo::MIN_MONTH = 1;
const unsigned int DateInfo::MAX_MONTH = 12;

const unsigned int DateInfo::MIN_DAY = 1;
const unsigned int DateInfo::DAYS_OF_MONTH[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

const unsigned int DateInfo::DAYS_OF_WEEK = 7;

InvalidDate::InvalidDate() : std::invalid_argument("Date invalid.") { }