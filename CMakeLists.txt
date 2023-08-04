cmake_minimum_required(VERSION 3.10)
project(Festival)

set(files 
	src/main.cpp
	src/DateInfo.cpp 
	src/Date.cpp 
	src/YearDate.cpp
	src/Festival.cpp
	src/DateFestival.cpp
	src/WeekDay.cpp
	src/YearWeekDay.cpp
	src/WeekDayFestival.cpp
	src/Calendar.cpp
	src/ControllerBase.cpp
	src/ControllerCLI.cpp
	src/FestivalList.cpp
	src/InterfaceCLI.cpp
	src/Exceptions.cpp
)

add_executable(${PROJECT_NAME} ${files})

target_include_directories(${PROJECT_NAME}
PRIVATE
	${PROJECT_SOURCE_DIR}/inc)
