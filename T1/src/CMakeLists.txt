# CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(MorningAlarm)

# Specify the required C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_STANDARD_REQUIRED True)   

# Define the executable
add_subdirectory(Alarm)
add_executable(MorningAlarm main.cpp)
target_link_libraries(MorningAlarm PUBLIC Alarm)
target_include_directories(MorningAlarm PUBLIC "${PROJECT_SOURCE_DIR}/Alarm")