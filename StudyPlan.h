#pragma once
#include <vector>
#include <string>
#include <map>
#include "Semester.h"
#include "Course.h"

class StudyPlan {
public:
    std::map<std::string, Course> courseCatalog;
    std::vector<Semester*> semesters;

    ~StudyPlan() {
        for (auto semester : semesters) {
            delete semester;
        }
    }

    void addSemester(std::string name, std::string type);
    void addCourseToSemester(const std::string& semesterName, const std::string& courseTitle);
};
