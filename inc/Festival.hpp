#ifndef __FESTIVAL_HPP__
#define __FESTIVAL_HPP__
#include "YearDate.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <utility>
#include <stdexcept>

/*****************************************
Name: Festival
Function: storing the information of festivals.
APIs: Add a festival (AddFestival).
      Delete a festival (DelFestival).
Developer & date: Keqian Tang 2023.7.12
******************************************/
class Festival {
private:
    std::string m_Name;                 //the name of the festival
    static unsigned int m_CurrentYear;
    /*****************************************
    Name: Festival
    Function: free the space.
    APIs: none
    Developer & date: Keqian Tang 2023.7.12
    ******************************************/
    class Garbo {
    public:
        ~Garbo() {                   //automatically execute Garbo's destructor at the end of the program.
            Festival::Clear();
        }
    };
    static Garbo m_Garbo; //when m_Garbo is destructed, it will free the space taken by Festival.

protected:
    void SetName(const std::string &Name);
    Festival(const std::string& Name);
    Festival(const char* Name) = delete;
    static std::vector<std::shared_ptr<Festival> > m_All; //store pointers pointing to festivals.

public:
    enum FesType {
        FES = 0,
        DATE_FES,
        WEEKDAY_FES
    };
    
    const std::string& Name;
    static const std::vector<std::shared_ptr<Festival> >& All;
    static const unsigned int& CurrentYear;

    virtual FesType GetType() const;
    virtual YearDate ToDate(const unsigned int Year) const;

    static void SetCurrentYear(const unsigned int Year);
    static std::shared_ptr<Festival> AddFestival(const std::string& Name);
    static std::shared_ptr<Festival> AddFestival(const char* Name) = delete;
    static void Clear();
    static void DelFestival(const std::string& Name);
    static void DelFestival(const char* Name) = delete;
    static const Festival& FindFestival(const std::string& Name);
    static const Festival& FindFestival(const char* Name) = delete;
    
    static void SortByYear(const unsigned int Year);

    virtual ~Festival();

    bool operator==(const Festival& aFes);
    bool operator!=(const Festival& aFes);
    bool operator<(const Festival& aFes);
    bool operator>(const Festival& aFes);
    bool operator<=(const Festival& aFes);
    bool operator>=(const Festival& aFes);

    friend std::ostream& operator<<(std::ostream& Stream, const Festival& aFes);
    friend std::istream& operator>>(std::istream& Stream, Festival& aFes);
};

#endif //__FESTIVAL_HPP__