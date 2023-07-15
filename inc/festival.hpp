#ifndef __FESTIVAL_HPP__
#define __FESTIVAL_HPP__
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <utility>

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

    void SetName(const std::string &Name);

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
    Festival(const std::string& Name);
    Festival(const char* Name) = delete;
    static std::vector<std::shared_ptr<Festival> > m_All; //store pointers pointing to festivals.

public:
    /*constant references*/
    const std::string &Name;
    /*static member functions*/
    static std::shared_ptr<Festival> AddFestival(const std::string &Name);
    static std::shared_ptr<Festival> AddFestival(const char *Name) = delete;
    static void Clear();
    static void DelFestival(const std::string &Name);
    static void DelFestival(const char *Name) = delete;
    virtual ~Festival() { }
};

#endif //__FESTIVAL_HPP__