#ifndef SEMESTER_H
#define SEMESTER_H

#include <string>
#include <vector>
#include "Course.h"

class StudyPlan;  // Forward declaration

class Semester {
private:
    std::string semesterName;
    int maxCredits;
    std::vector<Course> courses;

public:
    Semester(const std::string& name, int credits);
    bool canAddCourse(const Course& course, const StudyPlan& studyPlan) const;
    void addCourse(const Course& course, const StudyPlan& studyPlan);
    int getTotalCredits() const;
    std::string getSemesterName() const;
    const std::vector<Course>& getCourses() const;  // Getter for courses
};

#endif
