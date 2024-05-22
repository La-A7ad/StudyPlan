#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <map>

class Course {
private:
    std::string code;
    std::string title;
    int creditHours;
    std::vector<std::string> prerequisites;

public:
    Course() = default;
    Course(std::string code, std::string title, int creditHours, std::vector<std::string> prerequisites);

    static std::map<std::string, Course> courseCatalog;

    // Getter methods
    const std::string& getCode() const;
    const std::string& getTitle() const;
    int getCreditHours() const;
    const std::vector<std::string>& getPrerequisites() const;

    static std::vector<std::string> searchCourse(const std::string& courseCodePrefix);
};

#endif

