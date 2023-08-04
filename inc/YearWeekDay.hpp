#ifndef __YEARWEEKDAY_HPP__
#define __YEARWEEKDAY_HPP__

#include "WeekDay.hpp"

class YearWeekDay : public WeekDay{
private:
	unsigned int m_Year;
public:
	const unsigned int& Year;
	
	YearWeekDay(const unsigned int Year, 
	            const unsigned int Month,
				const int Week, 
				const DayType Day);
	void SetYear(const unsigned int Year);
	void SetYearWeekDay(const unsigned int Year,
	                    const unsigned int Month,
						const int Week, 
						const DayType Day);
						
	YearDate ToDate() const ;

	bool operator==(const YearWeekDay& aYearWeekDay) const;
	bool operator!=(const YearWeekDay& aYearWeekDay) const;
	bool operator<(const YearWeekDay& aYearWeekDay) const;
	bool operator>(const YearWeekDay& aYearWeekDay) const;
	bool operator<=(const YearWeekDay& aYearWeekDay) const;
	bool operator>=(const YearWeekDay& aYearWeekDay) const;
};

#endif