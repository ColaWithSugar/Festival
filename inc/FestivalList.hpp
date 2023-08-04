#ifndef __FESTIVAL_LIST_HPP__
#define __FESTIVAL_LIST_HPP__

#include "Festival.hpp"
#include <vector>
#include <utility>

class FestivalList {
protected:
	std::vector<std::pair<std::string, YearDate>> m_Festivals;
public:
	const std::vector<std::pair<std::string, YearDate>>& Festivals;
	FestivalList();
	void SearchIn(const YearDate& Date1, 
				  const YearDate& Date2,
				  const std::vector<std::shared_ptr<Festival>>& Data);
	static bool CompareByName(const std::pair<std::string, YearDate>& Date1,
	                          const std::pair<std::string, YearDate>& Date2);
	void SortByName();
};

#endif