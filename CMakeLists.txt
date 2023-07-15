cmake_minimum_required(VERSION 3.10)
project(Festival)

set(files 
	src/main.cpp
	src/date.cpp 
	src/dateinfo.cpp 
	src/yeardate.cpp
)

add_executable(${PROJECT_NAME} ${files})

target_include_directories(${PROJECT_NAME}
PRIVATE
	${PROJECT_SOURCE_DIR}/inc)
