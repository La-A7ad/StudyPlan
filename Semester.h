#pragma once
#include <string>
#include <vector>
#include <map>
#include "Course.h"

class Semester {
protected:
    int maxCredits;  // default maximum credits
    std::string semesterName;
public:
    std::vector<std::string> courses;

    Semester(std::string name, int credits) : semesterName(name), maxCredits(credits) {}

    bool canAddCourse(const Course& course);
     bool addCourse(const Course& course, const StudyPlan& studyPlan);

    // Getter method for semesterName
    std::string getSemesterName() const {
        return semesterName;
    }
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
