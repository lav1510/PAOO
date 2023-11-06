# CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(ring)

# Specify the required C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_STANDARD_REQUIRED True)   

# Define the executable
add_subdirectory(Alarm)
add_subdirectory(EnhancedAlarm)
add_subdirectory(Timer)
add_executable(ring main.cpp)
target_link_libraries(ring PUBLIC Alarm)
target_link_libraries(ring PUBLIC EnhancedAlarm)
target_link_libraries(ring PUBLIC Timer)
target_include_directories(ring PUBLIC "${PROJECT_SOURCE_DIR}/Alarm")
target_include_directories(ring PUBLIC "${PROJECT_SOURCE_DIR}/EnhancedAlarm")
target_include_directories(ring PUBLIC "${PROJECT_SOURCE_DIR}/Timer")