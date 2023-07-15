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
    : Name(m_Name) {
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

/*****************************************
Name: SetMonth
Function: setting the month of a festival.
Parameters: the month of the festival.
Return value: no return value.
Developer & date: Keqian Tang 2023.7.12
******************************************/

/*****************************************
Name: SetMonth
Function: setting the day of a festival.
Parameters: the day of the festival.
Return value: no return value.
Developer & date: Keqian Tang 2023.7.12
******************************************/

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
Function: deleting a single festival, given its name.
Parameters: the name of the target festival.
Return value: no return value.
Developer & date: Keqian Tang 2023.7.12
******************************************/
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

/***********************************************************
Name: GetFestivalByName
Function: get a single festival, given its name.
Parameters: the name of the target festival.
Return value: a pair containing the date (Month and Day) of the target festival.
Developer & date: Keqian Tang 2023.7.12
************************************************************/