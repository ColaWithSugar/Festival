#include "FestivalList.hpp"
#include <algorithm>

FestivalList::FestivalList() : Festivals(m_Festivals) { }

void FestivalList::SearchIn(const YearDate& Date1, 
				  const YearDate& Date2,
				  const std::vector<std::shared_ptr<Festival>>& Data) {
	for (unsigned int Year = Date1.Year; Year <= Date2.Year; Year++) {
		for (auto& n : Data) {
			YearDate FesDate = (*n).ToDate(Year);
			if (FesDate >= Date1 && FesDate <= Date2)
				m_Festivals.push_back(std::pair<std::string, YearDate>((*n).Name, FesDate));
		}
	}
}

bool FestivalList::CompareByName(const std::pair<std::string, YearDate>& Date1,
	               				 const std::pair<std::string, YearDate>& Date2) {
	return Date1.first < Date2.first;
}

void FestivalList::SortByName() {
	std::sort(m_Festivals.begin(), m_Festivals.end(), CompareByName);
}