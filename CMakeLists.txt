cmake_minimum_required(VERSION 3.29)
project(untitled8)

set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Add the executable and its source files
add_executable(untitled8
        main.cpp
        CLI.cpp
        StudyPlan.cpp
        Student.cpp
        Course.cpp
        Semester.cpp
)

# Find and link the nlohmann_json library
find_package(nlohmann_json REQUIRED)
target_link_libraries(CSAI_SP PRIVATE nlohmann_json::nlohmann_json)
