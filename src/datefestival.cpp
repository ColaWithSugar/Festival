#include "datefestival.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>

const unsigned int DateFestival::DayOfMonth[13] = {
	0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
const unsigned int DateFestival::MinMonth = 1;
const unsigned int DateFestival::MinDay = 1;
const unsigned int DateFestival::MaxMonth = 12;

DateFestival::DateFestival(const std::string& Name, unsigned int Month = 1, unsigned int Day = 1) 
	: Festival::Festival(Name), Month(m_Month), Day(m_Day) {
	SetDate(Month, Day);
}

bool DateFestival::IsValidDate(unsigned int Month, unsigned int Day) {
	if (Month < MinMonth || Month > MaxMonth) {
		return false;
	}
	else if (Day < MinDay || Day > DayOfMonth[Month]) {
		return false;
	}
	return true;
}

inline void DateFestival::SetDate(unsigned int Month, unsigned int Day) {
	if (IsValidDate(Month, Day) == false) {
		throw std::out_of_range("Date is not valid.");
	}
	SetMonth(Month);
	SetDay(Day);
}

inline void DateFestival::SetMonth(unsigned int Month) {
	m_Month = Month;
}

inline void DateFestival::SetDay(unsigned int Month) {
	m_Day = Day;
}

const DateFestival& DateFestival::AddFestival(
	const std::string& Name, unsigned int Month, unsigned Day) {
	std::for_each(m_All.begin(), m_All.end(), 
		[&](std::shared_ptr<Festival> p) { 
			if(p->Festival::Name == Name) { 
				throw std::invalid_argument("Festival already existed.");
			}
		}
	);
	m_All.push_back(std::shared_ptr<Festival>(
		static_cast<Festival*>(
			new DateFestival(Name, Month, Day))));
	return *static_cast<DateFestival*>(m_All.back().get());
}

void DateFestival::DelFestival(const std::string& Name) {
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

const DateFestival& DateFestival::FindFestival(const std::string& Name) {
	for (auto& n : m_All) {
		if (n->Name == Name) {
			return *static_cast<DateFestival*>(n.get());
		}
	}
	throw std::invalid_argument("Name not found.");
}

const DateFestival& DateFestival::ModifyFestival(const std::string& Name, unsigned int Month, unsigned int Day) {
	std::vector<std::shared_ptr<Festival> >::iterator itr;
	for (itr = m_All.begin(); itr != m_All.end(); itr++) {
		if ((*itr)->Name == Name) {
			static_cast<DateFestival*>((*itr).get())->SetDate(Month, Day);
			itr--;
			return *static_cast<DateFestival*>((*itr).get());
		}
	}
	throw std::invalid_argument("Name not found.");
}