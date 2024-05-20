#ifndef SEMESTER_H
#define SEMESTER_H

#include "Course.h"
#include <vector>
#include <string>

class StudyPlan;  // Forward declaration

class Semester {
private:
    std::string semesterName;
    int maxCredits;
    std::vector<Course> courses;

public:
    Semester(std::string name, int credits);

    bool canAddCourse(const Course& course, const StudyPlan& studyPlan);
    void addCourse(const Course& course, const StudyPlan& studyPlan);
    int getTotalCredits() const;
    std::string getSemesterName() const;
};

#endif
