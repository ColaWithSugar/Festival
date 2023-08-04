#include "FestivalList.hpp"
#include <algorithm>

/*****************************************
Name: FestivalList
Function: constructor of FestivalList
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
FestivalList::FestivalList() : Festivals(m_Festivals) { }

/*****************************************
Name: SearchIn
Function: Search festivals in an interval.
Parameters: None
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
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

/*****************************************
Name: CompareByName
Function: compare two festivals by their names.
Parameters: Two festivals in form [std::pair<std::string, YearDate>]
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
bool FestivalList::CompareByName(const std::pair<std::string, YearDate>& Date1,
	               				 const std::pair<std::string, YearDate>& Date2) {
	return Date1.first < Date2.first;
}

/*****************************************
Name: SortByName
Function: sort the list by festival names.
Parameters: Two festivals.
Return value: None
Developer & date: Keqian Tang 2023.8.2
******************************************/
void FestivalList::SortByName() {
	std::sort(m_Festivals.begin(), m_Festivals.end(), CompareByName);
}

/*****************************************
Name: operator=
Function: copy a FestivalList
Parameters: another FestivalList
Return value: the new FestivalList
Developer & date: Keqian Tang 2023.8.2
******************************************/
const FestivalList& FestivalList::operator=(const FestivalList& aList) {
	m_Festivals.assign(aList.Festivals.begin(), aList.Festivals.end());
	return *this;
}