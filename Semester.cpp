#include "Semester.h"
#include "StudyPlan.h"
#include <iostream>

Semester::Semester(const std::string& name, int maxCredits)
    : name(name), maxCredits(maxCredits) {}

bool Semester::addCourse(const Course& course, const StudyPlan& studyPlan) {
    // Check if all prerequisites are completed
    for (const auto& prereq : course.getPrerequisites()) {
        if (!studyPlan.hasCompletedCourse(prereq)) {
            std::cout << "Cannot add course " << course.getCode() << " - prerequisite " << prereq << " not completed." << std::endl;
            return false;
        }
    }

    int currentCredits = getTotalCredits();
    if (currentCredits + course.getCreditHours() <= maxCredits) {
        courses.push_back(course);
        return true;
    } else {
        std::cout << "Cannot add course " << course.getCode() << " - exceeds maximum credits." << std::endl;
        return false;
    }
}

void Semester::listCourses() const {
    std::cout << "Courses in " << name << " semester:" << std::endl;
    for (const auto& course : courses) {
        std::cout << course.getCode() << ": " << course.getTitle() << " (" << course.getCreditHours() << " credits)" << std::endl;
    }
}

const std::string& Semester::getName() const {
    return name;
}

int Semester::getMaxCredits() const {
    return maxCredits;
}

int Semester::getTotalCredits() const {
    int totalCredits = 0;
    for (const auto& course : courses) {
        totalCredits += course.getCreditHours();
    }
    return totalCredits;
}

//test
