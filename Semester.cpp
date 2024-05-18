#include "Semester.h"
#include <algorithm>
#include <iostream>

bool Semester::canAddCourse(const Course& course) {
    if (courses.size() >= maxCredits) {
        std::cout << "Max credit limit reached for this semester.\n";
        return false;
    }

    // Check if the course exists in the catalog
    if (Course::courseCatalog.find(course.title) == Course::courseCatalog.end()) {
        std::cout << "Course does not exist in the catalog.\n";
        return false;
    }

    // Check if prerequisites are met
    for (const auto& prereq : course.prerequisites) {
        if (std::find(courses.begin(), courses.end(), prereq) == courses.end()) {
            std::cout << "Prerequisite " << prereq << " not met.\n";
            return false;
        }
    }

    return true;
}

void Semester::addCourse(const std::string& courseTitle) {
    if (canAddCourse(Course::courseCatalog.at(courseTitle))) {
        courses.push_back(courseTitle);
        std::cout << "Course " << courseTitle << " added successfully.\n";
    }
}
