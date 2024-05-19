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
    Course(std::string code, std::string title, int creditHours, std::vector<std::string> prerequisites);

    static std::map<std::string, Course> courseCatalog;

    const std::vector<std::string>& getPrerequisites() const;
    const std::string& getCode() const;
    const std::string& getTitle() const;
    int getCreditHours() const;
    static std::vector<std::string> searchCourse(const std::string& courseCodePrefix);

    
};

#endif

//Yousef Hosam Ahmed