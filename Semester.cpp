#include "Semester.h"
#include "StudyPlan.h"
#include <iostream>

bool Semester::canAddCourse(const Course& course, const StudyPlan& studyPlan) const {
    for (const auto& sem : studyPlan.getSemesters()) {
        for (const auto& c : sem.getCourses()) {
            for (const auto& prereq : course.getPrerequisites()) {
                if (prereq == c.getCode()) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Semester::addCourse(const Course& course, const StudyPlan& studyPlan) {
    if (!canAddCourse(course, studyPlan)) {
        std::cout << "Cannot add course " << course.getCode() << " due to unmet prerequisites.\n";
        return;
    }

    int currentCredits = getTotalCredits();
    int additionalCredits = course.getCredits();
    bool isOnProbation = studyPlan.isStudentOnProbation();
    int maxCredits = 18;

    if (isOnProbation) {
        maxCredits = 12;
    } else if (studyPlan.canOverload()) {
        maxCredits = 21;
    }

    if (currentCredits + additionalCredits > maxCredits) {
        std::cout << "Cannot register more than " << maxCredits << " credits.\n";
        return;
    }

    courses.push_back(course);
    std::cout << "Course " << course.getCode() << " added successfully.\n";
}

int Semester::getTotalCredits() const {
    int totalCredits = 0;
    for (const auto& course : courses) {
        totalCredits += course.getCredits();
    }
    return totalCredits;
}

std::string Semester::getSemesterName() const {
    return semesterName;
}
