#include "festival.hpp"
#include <stdexcept>
#include <iostream>
std::vector<std::shared_ptr<Festival>> Festival::m_All{};
Festival::Garbo Festival::m_Garbo{};

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
    : Name(m_Name), CurrentYear(m_CurrentYear) {
    SetName(Name);
}

/*****************************************
Name: SerName
Function: setting the name of a festival.
Parameters: the name of the festival (Name).
Return value: no return value.
Developer & date: Keqian Tang 2023.7.12
******************************************/
inline void Festival::SetName(const std::string &Name) {
    m_Name = Name;
}

Festival::FesType Festival::GetType() const {
    return Fes;
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

void Festival::DelFestival(const std::string& Name) {
    std::vector<std::shared_ptr<Festival>>::iterator it;
    for (it = m_All.begin(); it != m_All.end(); it++) {
        if ((*it)->Name == Name) {
            m_All.erase(it);
            return;
        }
    }
    throw std::invalid_argument("Name not found.");
}

bool Festival::operator==(const Festival& aFes) {
    return this->ToDate(CurrentYear) == aFes.ToDate(aFes.CurrentYear);
}

bool Festival::operator!=(const Festival& aFes) {
    return this->ToDate(CurrentYear) != aFes.ToDate(aFes.CurrentYear);
}

bool Festival::operator<(const Festival& aFes) {
    return this->ToDate(CurrentYear) < aFes.ToDate(aFes.CurrentYear);
}

bool Festival::operator>(const Festival& aFes) {
    return this->ToDate(CurrentYear) > aFes.ToDate(aFes.CurrentYear);
}

bool Festival::operator<=(const Festival& aFes) {
    return this->ToDate(CurrentYear) <= aFes.ToDate(aFes.CurrentYear);
}

bool Festival::operator>=(const Festival& aFes) {
    return this->ToDate(CurrentYear) >= aFes.ToDate(aFes.CurrentYear);
}

NameNotFound::NameNotFound() : invalid_argument("Name not found.") { }

DateNotFound::DateNotFound() : invalid_argument("Date not found.") { } 