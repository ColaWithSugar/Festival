#include "datefestival.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>

DateFestival::DateFestival(const std::string& Name, unsigned int Month = 1, unsigned int Day = 1) 
	: Festival::Festival(Name), m_Date(Month, Day), Month(m_Date.Month), Day(m_Date.Day) {
	return;
}

DateFestival::FesType DateFestival::GetType() const {
	return DateFes;
}

YearDate DateFestival::ToDate(const unsigned int Year) const {
	return YearDate(Year, m_Date.Month, m_Date.Day);
}

inline void DateFestival::SetDate(unsigned int Month, unsigned int Day) {
	if (IsValidDate(Month, Day) == false) {
		throw std::out_of_range("Date is not valid.");
	}
	SetMonth(Month);
	SetDay(Day);
}

bool DateFestival::IsValidDate(const unsigned int Month, const unsigned int Day) {
	return Date::IsValidDate(Month, Day);
}

bool DateFestival::IsValidDate() {
	return m_Date.IsValidDate();
}

inline void DateFestival::SetMonth(const unsigned int Month) {
	m_Date.SetMonth(Month);
}

inline void DateFestival::SetDay(const unsigned int Month) {
	m_Date.SetMonth(Day);
}

inline void DateFestival::SetDate(const unsigned int Month, const unsigned int Day) {
	m_Date.SetDate(Month, Day);
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

bool DateFestival::operator==(const DateFestival& aFestival) const {
	return this->m_Date == aFestival.m_Date;
}

bool DateFestival::operator!=(const DateFestival& aFestival) const {
	return this->m_Date != aFestival.m_Date;
}

bool DateFestival::operator<(const DateFestival& aFestival) const {
	return this->m_Date < aFestival.m_Date;
}

bool DateFestival::operator>(const DateFestival& aFestival) const {
	return this->m_Date > aFestival.m_Date;
}

bool DateFestival::operator<=(const DateFestival& aFestival) const {
	return this->m_Date <= aFestival.m_Date;
}

bool DateFestival::operator>=(const DateFestival& aFestival) const {
	return this->m_Date >= aFestival.m_Date;
}