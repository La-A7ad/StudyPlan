#ifndef SEMESTER_H
#define SEMESTER_H

#include <vector>
#include <string>
#include "Course.h"

class Semester {
private:
    std::string semesterName;
    int maxCredits;
    std::vector<Course> courses;

public:
    Semester(std::string name, int credits) : semesterName(name), maxCredits(credits) {}

    bool canAddCourse(const Course& course, const StudyPlan& studyPlan) const;
    void addCourse(const Course& course, const StudyPlan& studyPlan);
    int getTotalCredits() const;
    std::string getSemesterName() const;
    const std::vector<Course>& getCourses() const; // Add this method

};

#endif
