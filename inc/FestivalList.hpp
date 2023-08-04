/***********************************
 * File Name: FestivalList.hpp
 * Function: declare class FestivalList
 * Developer(s) & Date: Keqian Tang | 2023-8-1
************************************/

#ifndef __FESTIVAL_LIST_HPP__
#define __FESTIVAL_LIST_HPP__

#include "Festival.hpp"
#include <vector>
#include <utility>

/*****************************************
Name: FestivalList
Function: storing a list of festivals and their years.
APIs: Search festivals in an interval (SearchIn)
	  Compare two festivals by names (CompareByName)
	  Sort festivals by names (SortByName)
Developer & date: Keqian Tang 2023.7.12
******************************************/
class FestivalList {
protected:
	std::vector<std::pair<std::string, YearDate>> m_Festivals; //storing festivals with years.
public:
	const std::vector<std::pair<std::string, YearDate>>& Festivals;
	FestivalList();
	void SearchIn(const YearDate& Date1, 
				  const YearDate& Date2,
				  const std::vector<std::shared_ptr<Festival>>& Data);
	static bool CompareByName(const std::pair<std::string, YearDate>& Date1,
	                          const std::pair<std::string, YearDate>& Date2);
	void SortByName();
	const FestivalList& operator=(const FestivalList& aList);
};

#endif