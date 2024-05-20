#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <map>

class Course {
public:
    std::string name;
    int credits;
    std::vector<std::string> prerequisites;

    Course() = default;
    Course(std::string name, int credits, std::vector<std::string> prerequisites);

    static std::map<std::string, Course> courseCatalog;

    static std::vector<std::string> searchCourse(const std::string& courseCodePrefix);

    // Add getter methods
    const std::vector<std::string>& getPrerequisites() const;
    const std::string& getCode() const;
    int getCredits() const;
};

#endif
