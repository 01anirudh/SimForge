cmake_minimum_required(VERSION 3.14)
project(SimForge VERSION 1.0 DESCRIPTION "Real-Time Discrete-Event Simulation Engine")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories
include_directories(include)

# Main executable
add_executable(SimForge src/main.cpp src/EventCalendar.cpp)
target_include_directories(SimForge PRIVATE include)

# Fetch GoogleTest
# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

# enable_testing()

# add_executable(SimForgeTests
#     tests/test_event_calendar.cpp
#     src/EventCalendar.cpp
# )
# target_include_directories(SimForgeTests PRIVATE include)
# target_link_libraries(SimForgeTests gtest_main)

# include(GoogleTest)
# gtest_discover_tests(SimForgeTests)
