#include "Semester.h"
#include "StudyPlan.h"
#include "Course.h"
#include <iostream>

Semester::Semester(std::string name, int credits) : semesterName(std::move(name)), maxCredits(credits) {}

bool Semester::canAddCourse(const Course& course, const StudyPlan& studyPlan) {
    // Check if prerequisites are met
    const auto& prerequisites = course.getPrerequisites();
    for (const auto& prereq : prerequisites) {
        bool found = false;
        for (const auto& prevSemester : studyPlan.getSemesters()) {
            for (const auto& takenCourse : prevSemester->courses) {
                if (takenCourse.getCode() == prereq) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (!found) {
            std::cout << "Prerequisite " << prereq << " not met for course " << course.getCode() << ".\n";
            return false;
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
            return false;
        }
    } else if (currentCredits + additionalCredits > 18) {
        std::cout << "Cannot register more than 18 credits.\n";
        return false;
    }

    return true;
}

void Semester::addCourse(const Course& course, const StudyPlan& studyPlan) {
    if (canAddCourse(course, studyPlan)) {
        courses.push_back(course);
        std::cout << "Course " << course.getCode() << " added successfully.\n";
    }
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
