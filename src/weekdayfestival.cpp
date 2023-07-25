#include "weekdayfestival.hpp"
#include "dateinfo.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>

WeekDayFestival::WeekDayFestival(
	const std::string& Name, unsigned int Month, unsigned int Week, unsigned int Day) :
	Festival::Festival(Name), 
	m_WeekDay(Month, Week, Day), 
	Month(m_WeekDay.Month), 
	Day(m_WeekDay.Day), 
	Week(m_WeekDay.Week) {
	return;
}

WeekDayFestival::FesType WeekDayFestival::GetType() const {
	return WeekDayFes;
}

bool WeekDayFestival::IsValidWeekDay(unsigned int Month, unsigned int Week, unsigned int Day) {
	if (Day < DateInfo::MIN_DAY || Day > DateInfo::DAYS_OF_WEEK) {
		return false;
	}
	else if (Month < DateInfo::MIN_MONTH || Month > DateInfo::MAX_MONTH) {
		return false;
	}
	else if (Week < DateInfo::MIN_DAY || DateInfo::DAYS_OF_WEEK * Week > DateInfo::DAYS_OF_MONTH[DateInfo::LEAP][Month]) {
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
	m_WeekDay.SetWeek(Week);
}

inline void WeekDayFestival::SetMonth(unsigned int Month) {
	m_WeekDay.SetMonth(Month);
}

inline void WeekDayFestival::SetDay(unsigned int Day) {
	m_WeekDay.SetDay(Day);
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