#ifndef SEMESTER_H
#define SEMESTER_H

#include <string>
#include <vector>
#include "Course.h"

// Forward declare StudyPlan
class StudyPlan;

class Semester {
private:
    std::string name;
    int maxCredits;
    std::vector<Course> courses;

public:
    Semester(const std::string& name, int maxCredits);

    bool addCourse(const Course& course, const StudyPlan& studyPlan);
    void listCourses() const;

    const std::string& getName() const;
    int getMaxCredits() const;
    int getTotalCredits() const;
};

#endif // SEMESTER_H


//Yousef Hosam Ahmed