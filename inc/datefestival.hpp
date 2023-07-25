#ifndef __DATEFESTIVAL_HPP__
#define __DATEFESTIVAL_HPP__

#include "festival.hpp"
#include "date.hpp"
#include "yeardate.hpp"

class DateFestival : public Festival{
private:
	Date m_Date;
	static bool IsValidDate(unsigned int Month, unsigned int Day);
	bool IsValidDate();

protected:
	void SetMonth(const unsigned int Month);
	void SetDay(const unsigned int Day);
	void SetDate(const unsigned int Month, unsigned int Day);
	DateFestival(const std::string& Name, unsigned int Month, unsigned int Day);

public:
	const unsigned int& Day;
	const unsigned int& Month;
	
	FesType GetType() const;
	YearDate ToDate(const unsigned int Year) const;

	static void DelFestival(const std::string& Name);
	static void DelFestival(const char* Name) = delete;
	
	static const DateFestival& AddFestival(const std::string& Name, unsigned int Month, unsigned int Day);
	static const DateFestival& AddFestival(const char* Name, unsigned int Month, unsigned int Day) = delete;
	
	static const DateFestival& FindFestival(const std::string& Name);
	static const DateFestival& FindFestival(const char* Name) = delete;
	
	static const DateFestival& ModifyFestival(const std::string& Name, unsigned int Month, unsigned int Day);
	static const DateFestival& ModifyFestival(const char* Name, unsigned int Month, unsigned int Day) = delete;

	bool operator==(const DateFestival& aFestival) const;
	bool operator!=(const DateFestival& aFestival) const;
	bool operator<(const DateFestival& aFestival) const;
	bool operator>(const DateFestival& aFestival) const;
	bool operator<=(const DateFestival& aFestival) const;
	bool operator>=(const DateFestival& aFestival) const;
	// friend bool operator==(const DateFestival& DateFestivalA, const DateFestival& DateFestivalB);
	// friend bool operator!=(const DateFestival& DateFestivalA, const DateFestival& DateFestivalB);
	// friend bool operator<(const DateFestival& DateFestivalA, const DateFestival& DateFestivalB);
	// friend bool operator>(const DateFestival& DateFestivalA, const DateFestival& DateFestivalB);
	// friend bool operator<=(const DateFestival& DateFestivalA, const DateFestival& DateFestivalB);
	// friend bool operator>=(const DateFestival& DateFestivalA, const DateFestival& DateFestivalB);
};

#endif