#pragma once
#include <string>
#include <vector>
#include <map>
#include "Course.h"

class StudyPlan;

class Semester {
protected:
    int maxCredits;  // default maximum credits
    std::string semesterName;
    std::vector<Course> courses;
public:
     Semester(std::string name, int credits);
    void addCourse(const Course& course, const StudyPlan& studyPlan);
    bool hasCourse(const std::string& courseCode) const;
    int getTotalCredits() const;
    std::string getSemesterName() const { return semesterName; }
};

class FallSemester : public Semester {
public:
    FallSemester(std::string name, bool overload)
        : Semester(name, overload ? 21 : 18) {}
};

class SpringSemester : public Semester {
public:
    SpringSemester(std::string name, bool overload)
        : Semester(name, overload ? 21 : 18) {}
};

class SummerSemester : public Semester {
public:
    SummerSemester(std::string name)
        : Semester(name, 7) {}
};
