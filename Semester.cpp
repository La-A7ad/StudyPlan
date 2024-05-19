#include "Semester.h"
#include "StudyPlan.h"
#include <iostream>

Semester::Semester(std::string name, int credits)
    : maxCredits(credits), semesterName(name) {}  // Fix initializer order

void Semester::addCourse(const Course& course, const StudyPlan& studyPlan) {
    for (const std::string& prereq : course.getPrerequisites()) {
        bool completed = false;
        for (const auto& sem : studyPlan.getSemesters()) {
            if (sem->hasCourse(prereq)) {
                completed = true;
                break;
            }
        }
        if (!completed) {
            std::cout << "Prerequisite " << prereq << " for course " << course.getCode() << " not completed.\n";
            return;
        }
    }

    int currentCredits = getTotalCredits();
    int additionalCredits = course.getCredits();
    bool isOnProbation = studyPlan.isStudentOnProbation();

    int maxCredits = 18;
    if (isOnProbation) {
        maxCredits = 12;
        if (currentCredits + additionalCredits > maxCredits) {
            std::cout << "Warning: You are on probation and can only register up to 12 credits.\n";
        }
    } else if (studyPlan.canOverload()) {
        maxCredits = 21;
        if (currentCredits + additionalCredits > 21) {
            std::cout << "Cannot register more than 21 credits as an overloader.\n";
            return;
        }
    } else if (currentCredits + additionalCredits > 18) {
        std::cout << "Cannot register more than 18 credits.\n";
        return;
    }

    courses.push_back(course);
    std::cout << "Course " << course.getCode() << " added successfully.\n";
}

bool Semester::hasCourse(const std::string& courseCode) const {
    for (const auto& course : courses) {
        if (course.getCode() == courseCode) {
            return true;
        }
    }
    return false;
}

int Semester::getTotalCredits() const {
    int totalCredits = 0;
    for (const auto& course : courses) {
        totalCredits += course.getCredits();
    }
    return totalCredits;
}
