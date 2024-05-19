#pragma once
#include <vector>
#include <string>
#include <map>

class Course {
public:
    std::string title;
    int creditHours;
    std::vector<std::string> prerequisites;

    Course(std::string t, int ch, std::vector<std::string> preqs)
        : title(t), creditHours(ch), prerequisites(preqs) {}

    static std::map<std::string, Course> courseCatalog;
    static std::vector<std::string> searchCourse(const std::string& courseCodePrefix);
};
