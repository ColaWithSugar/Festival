#include <iostream>
#include <stdexcept>
#include "date.hpp"
#include "yeardate.hpp"
#include "datefestival.hpp"
#include "weekdayfestival.hpp"

int main() {

    YearDate x(2004, 9, 26);
    std::cout << x << std::endl;
    std::cin >> x;
    std::cout << x << std::endl;
    // bool AlwaysTrue = true;
    // while (AlwaysTrue == true) {
    //     std::string Category;
    //     std::string Cmd;
    //     std::string Name;
    //     unsigned int Month;
    //     unsigned int Day;
    //     unsigned int Week;
    //     unsigned int Num;
    //     std::cin >> Category;
    //     if (Category == "date") {
    //         std::cin >> Cmd;
    //         if (Cmd == "end") {
    //             break;
    //         }
    //         else if (Cmd == "add") {
    //             std::cin >> Name >> Month >> Day;
    //             try {
    //                 std::cout << DateFestival::AddFestival(Name, Month, Day).Name << std::endl;
    //             }
    //             catch (std::exception& e) {
    //                 std::cout << e.what() << std::endl;
    //             }
    //         }
    //         else if (Cmd == "del") {
    //             std::cin >> Name;
    //             try {
    //                 DateFestival::DelFestival(Name);
    //             }
    //             catch (std::exception& e) {
    //                 std::cout << e.what() << std::endl;
    //             }
    //         }
    //         else if (Cmd == "find") {
    //             std::cin >> Name;
    //             try {
    //                 const DateFestival& x = DateFestival::FindFestival(Name);
    //                 std::cout << x.Name << ' ' << x.Month << ' ' << x.Day << std::endl;
    //             }
    //             catch (std::exception& e) {
    //                 std::cout << e.what() << std::endl;
    //             }
    //         }
    //         else if (Cmd == "mod") {
    //             std::cin >> Name >> Month >> Day;
    //             try {
    //                 DateFestival::ModifyFestival(Name, Month, Day);
    //             }
    //             catch (std::exception& e) {
    //                 std::cout << e.what() << std::endl;
    //             }
    //         }
    //     }
    //     else if (Category == "week") {
    //         std::cin >> Cmd;
    //         if (Cmd == "end") {
    //             break;
    //         }
    //         else if (Cmd == "add") {
    //             std::cin >> Name >> Month >> Week >> Day;
    //             try {
    //                 std::cout << WeekDayFestival::AddFestival(Name, Month, Week, Day).Name << std::endl;
    //             }
    //             catch (std::exception& e) {
    //                 std::cout << e.what() << std::endl;
    //             }
    //         }
    //         else if (Cmd == "del") {
    //             std::cin >> Name;
    //             try {
    //                 WeekDayFestival::DelFestival(Name);
    //             }
    //             catch (std::exception& e) {
    //                 std::cout << e.what() << std::endl;
    //             }
    //         }
    //         else if (Cmd == "find") {
    //             std::cin >> Name;
    //             try {
    //                 const WeekDayFestival& x = WeekDayFestival::FindFestival(Name);
    //                 std::cout << x.Name << ' ' << x.Month << ' ' << x.Week << ' ' << x.Day << std::endl;
    //             }
    //             catch (std::exception& e) {
    //                 std::cout << e.what() << std::endl;
    //             }
    //         }
    //         else if (Cmd == "mod") {
    //             std::cin >> Name >> Month >> Week >> Day;
    //             try {
    //                 WeekDayFestival::ModifyFestival(Name, Month, Week, Day);
    //             }
    //             catch (std::exception& e) {
    //                 std::cout << e.what() << std::endl;
    //             }
    //         }
    //     }
    // }
    return 0;
}