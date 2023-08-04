#include "Festival.hpp"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <algorithm>

std::vector<std::shared_ptr<Festival>> Festival::m_All{};
Festival::Garbo Festival::m_Garbo{};
unsigned int Festival::m_CurrentYear = DateInfo::MIN_YEAR;
const unsigned int& Festival::CurrentYear = Festival::m_CurrentYear;
const std::vector<std::shared_ptr<Festival> >& Festival::All = Festival::m_All;

/*****************************************
Name: AddFestival.
Function: adding a festival.
Parameters: the name of the festival (Name), the date of the festival (Month and Day).
Return value: A pointer pointing to the festival.
Developer & date: Keqian Tang 2023.7.12
******************************************/
std::shared_ptr<Festival> Festival::AddFestival(const std::string &Name) {
    for (auto &n : m_All) {
        if (n->m_Name == Name) {
            throw std::invalid_argument("The festival already exists!");
        }
    }
    m_All.push_back(std::shared_ptr<Festival>(new Festival(Name)));
    return m_All.back();
}

/*****************************************
Name: Festival
Function: the constructor of class Festival, given the name and date of the festival.
Parameters: the name of the festival (Name), the date of the festival (Month and Day).
Return value: no return value.
Developer & date: Keqian Tang 2023.7.12
******************************************/
Festival::Festival(const std::string &Name) 
    : Name(m_Name) {
    SetName(Name);
}

/*****************************************
Name: ~Festival
Function: the destructor of class Festival.
Parameters: none
Return value: none
Developer & date: Keqian Tang 2023.7.12
******************************************/
Festival::~Festival() { }

/*****************************************
Name: SetName
Function: setting the name of a festival.
Parameters: the name of the festival (Name).
Return value: no return value.
Developer & date: Keqian Tang 2023.7.12
******************************************/
inline void Festival::SetName(const std::string &Name) {
    m_Name = Name;
}

/*****************************************
Name: GetType
Function: identify the object.
Parameters: None
Return value: enum FesType representing Festival.
Developer & date: Keqian Tang 2023.7.21
******************************************/
Festival::FesType Festival::GetType() const {
    return FES;
}

YearDate Festival::ToDate(const unsigned int Year) const {
    throw DateNotFound();
}

void Festival::SetCurrentYear(const unsigned int Year) {
    m_CurrentYear = Year;
}

/*****************************************
Name: Clear
Function: removing all festivals.
Parameters: empty.
Return value: no return value.
Developer & date: Keqian Tang 2023.7.12
******************************************/
void Festival::Clear()
{
    m_All.clear();
}

/*****************************************
Name: DelFestival
Function: Delete a festival providing its name
Parameters: Name
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
void Festival::DelFestival(const std::string& Name) {
    std::vector<std::shared_ptr<Festival>>::iterator it;
    for (it = m_All.begin(); it != m_All.end(); it++) {
        if ((*it)->Name == Name) {
            m_All.erase(it);
            return;
        }
    }
    throw NameNotFound();
}

/*****************************************
Name: FindFestival
Function: find a festival providing its name
Parameters: Name
Return value: const Festival& (a reference to the new Festival)
Developer & date: Keqian Tang 2023.7.21
******************************************/
const Festival& Festival::FindFestival(const std::string& Name) {
	std::vector<std::shared_ptr<Festival> >::iterator itr;
	for (itr = m_All.begin(); itr != m_All.end(); itr++) {
		if ((*itr)->Name == Name) {
			return **itr;
		}
	}
	throw NameNotFound();
}

/*****************************************
Name: SortByYear
Function: sort festivals in a certain year.
Parameters: Year
Return value: None
Developer & date: Keqian Tang 2023.7.21
******************************************/
void Festival::SortByYear(const unsigned int Year) {
    m_CurrentYear = Year;
    std::sort(m_All.begin(), m_All.end());
}

/*****************************************
Name: operator==
Function: check wether to Dates are the same.
Parameters: another Festival
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool Festival::operator==(const Festival& aFes) {
    return this->ToDate(CurrentYear) == aFes.ToDate(CurrentYear);
}

/*****************************************
Name: operator!=
Function: check wether two Dates are different.
Parameters: another Festival
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool Festival::operator!=(const Festival& aFes) {
    return this->ToDate(CurrentYear) != aFes.ToDate(CurrentYear);
}

/*****************************************
Name: operator<
Function: check wether the date of this fesival is earlier than another.
Parameters: another Festival
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool Festival::operator<(const Festival& aFes) {
    return this->ToDate(CurrentYear) < aFes.ToDate(CurrentYear);
}

/*****************************************
Name: operator>
Function: check wether the date of this fesival is later than another.
Parameters: another Festival
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool Festival::operator>(const Festival& aFes) {
    return this->ToDate(CurrentYear) > aFes.ToDate(CurrentYear);
}

/*****************************************
Name: operator<=
Function: check wether the date of this fesival is not later than another.
Parameters: another Festival
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool Festival::operator<=(const Festival& aFes) {
    return this->ToDate(CurrentYear) <= aFes.ToDate(CurrentYear);
}

/*****************************************
Name: operator>=
Function: check wether the date of this fesival is not ealier than another.
Parameters: another Festival
Return value: bool (yes or no)
Developer & date: Keqian Tang 2023.7.21
******************************************/
bool Festival::operator>=(const Festival& aFes) {
    return this->ToDate(CurrentYear) >= aFes.ToDate(CurrentYear);
}