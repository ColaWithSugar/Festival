#ifndef __YEARWEEKDAY_HPP__
#define __YEARWEEKDAY_HPP__

#include "weekday.hpp"

class YearWeekDay : public WeekDay{
private:
	unsigned int m_Year;
public:
	const unsigned int& Year;
	
	YearWeekDay(const unsigned int Year, 
	            const unsigned int Month,
				const unsigned int Week, 
				const unsigned int Day);
	void SetYear(const unsigned int Year);
	void SetYearWeekDay(const unsigned int Year,
	                    const unsigned int Month,
						const unsigned int Week, 
						const unsigned int Day);
						
	YearDate ToDate() const ;

	bool operator==(const YearWeekDay& aYearWeekDay) const;
	bool operator!=(const YearWeekDay& aYearWeekDay) const;
	bool operator<(const YearWeekDay& aYearWeekDay) const;
	bool operator>(const YearWeekDay& aYearWeekDay) const;
	bool operator<=(const YearWeekDay& aYearWeekDay) const;
	bool operator>=(const YearWeekDay& aYearWeekDay) const;
};

#endif