#pragma once
#include <vector>
#include <string>
#include <map>

class Course {
public:
    std::string code;
    int credits;
    std::vector<std::string> prerequisites;

    Course(std::string c, int cr, std::vector<std::string> prereqs)
        : code(c), credits(cr), prerequisites(prereqs) {}

    std::string getCode() const { return code; }
    static std::map<std::string, Course> courseCatalog;
     int getCredits() const { return credits; }
    static std::vector<std::string> searchCourse(const std::string& courseCodePrefix);
};
