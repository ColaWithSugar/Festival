#include "weekdayfestival.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>

const unsigned int WeekDayFestival::DayOfMonth[13] = {
	0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
const unsigned int WeekDayFestival::MinWeek = 1;
const unsigned int WeekDayFestival::MinDay = 1;
const unsigned int WeekDayFestival::MaxMonth = 12;
const unsigned int WeekDayFestival::MinMonth = 1;
const unsigned int WeekDayFestival::DayOfWeek = 7;

WeekDayFestival::WeekDayFestival(
	const std::string& Name, unsigned int Month = 0, unsigned int Week = 0, unsigned int Day = 0) 
	: Festival::Festival(Name), Week(m_Week), Month(m_Month), Day(m_Day) {
	SetWeekDay(Month, Week, Day);
}

bool WeekDayFestival::IsValidWeekDay(unsigned int Month, unsigned int Week, unsigned int Day) {
	if (Day < MinDay || Day > DayOfWeek) {
		return false;
	}
	else if (Month < MinMonth || Month > MaxMonth) {
		return false;
	}
	else if (Week < MinWeek || DayOfWeek * Week > DayOfMonth[Month]) {
		return false;
	}
	return true;
}

inline void WeekDayFestival::SetWeekDay(unsigned int Month, unsigned int Week, unsigned int Day) {
	if (IsValidWeekDay(Month, Week, Day) == false) {
		throw std::out_of_range("Date is not valid.");
	}
	SetWeek(Week);
	SetMonth(Month);
	SetDay(Day);
}

inline void WeekDayFestival::SetWeek(unsigned int Week) {
	m_Week = Week;
}

inline void WeekDayFestival::SetMonth(unsigned int Month) {
	m_Month = Month;
}

inline void WeekDayFestival::SetDay(unsigned int Day) {
	m_Day = Day;
}

const WeekDayFestival& WeekDayFestival::AddFestival(
	const std::string& Name, unsigned int Month, unsigned int Week, unsigned int Day) {
	std::for_each(m_All.begin(), m_All.end(), 
		[&](std::shared_ptr<Festival> p) { 
			if(p->Festival::Name == Name) { 
				throw std::invalid_argument("Festival already existed.");
			}
		}
	);
	m_All.push_back(std::shared_ptr<Festival>(
		static_cast<Festival*>(
			new WeekDayFestival(Name, Month, Week, Day))));
	return *static_cast<WeekDayFestival*>(m_All.back().get());
}

void WeekDayFestival::DelFestival(const std::string& Name) {
	std::vector<std::shared_ptr<Festival> >::iterator itr;
	for (itr = m_All.begin(); itr != m_All.end(); itr++) {
		if ((*itr)->Name == Name) {
			m_All.erase(itr);
			itr--;
			return;
		}
	}
	throw std::invalid_argument("Name not found.");
}

const WeekDayFestival& WeekDayFestival::FindFestival(const std::string& Name) {
	for (auto& n : m_All) {
		if (n->Name == Name) {
			return *static_cast<WeekDayFestival*>(n.get());
		}
	}
	throw std::invalid_argument("Name not found.");
}

const WeekDayFestival& WeekDayFestival::ModifyFestival(const std::string& Name, unsigned int Month, unsigned int Week, unsigned int Day) {
	std::vector<std::shared_ptr<Festival> >::iterator itr;
	for (itr = m_All.begin(); itr != m_All.end(); itr++) {
		if ((*itr)->Name == Name) {
			static_cast<WeekDayFestival*>((*itr).get())->SetWeekDay(Month, Week, Day);
			itr--;
			return *static_cast<WeekDayFestival*>((*itr).get());
		}
	}
	throw std::invalid_argument("Name not found.");
}