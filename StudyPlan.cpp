#include "StudyPlan.h"
#include <iostream>

void StudyPlan::addSemester(const Semester& semester) {
    semesters.push_back(semester);
}

void StudyPlan::addCourseToSemester(const std::string& semesterName, const std::string& courseCode) {
    for (auto& semester : semesters) {
        if (semester.getName() == semesterName) {
            auto it = Course::courseCatalog.find(courseCode);
            if (it != Course::courseCatalog.end()) {
                if (semester.addCourse(it->second)) {
                    std::cout << "Course " << courseCode << " added to " << semesterName << " semester." << std::endl;
                } else {
                    std::cout << "Failed to add course " << courseCode << " to " << semesterName << " semester." << std::endl;
                }
            } else {
                std::cout << "Course " << courseCode << " not found in catalog." << std::endl;
            }
            return;
        }
    }
    std::cout << "Semester " << semesterName << " not found." << std::endl;
}

void StudyPlan::listCoursesInSemester(const std::string& semesterName) const {
    for (const auto& semester : semesters) {
        if (semester.getName() == semesterName) {
            semester.listCourses();
            return;
        }
    }
    std::cout << "Semester " << semesterName << " not found." << std::endl;
}
