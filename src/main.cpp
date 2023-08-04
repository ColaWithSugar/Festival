#include <string>
#include <iostream>
#include <stdexcept>
#include "Date.hpp"
#include "YearDate.hpp"
#include "DateFestival.hpp"
#include "WeekDayFestival.hpp"
#include "ControllerCLI.hpp"
#include "InterfaceCLI.hpp"

int main() {
    ControllerCLI App("../Data/");
    App.Start();
}