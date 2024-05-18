#include "StudyPlan.h"
#include <iostream>

void StudyPlan::addSemester(std::string name, std::string type) {
    if (type == "Fall") {
        semesters.push_back(new FallSemester(name, true)); // Assume overload is allowed for demo
    } else if (type == "Spring") {
        semesters.push_back(new SpringSemester(name, true)); // Assume overload is allowed for demo
    } else if (type == "Summer") {
        semesters.push_back(new SummerSemester(name));
    } else {
        std::cout << "Invalid semester type.\n";
        return;
    }
    std::cout << "Semester " << name << " added.\n";
}

void StudyPlan::addCourseToSemester(const std::string& semesterName, const std::string& courseCode) {
    for (auto semester : semesters) {
        if (semester->getSemesterName() == semesterName) {
            // Check if the course exists in the courseCatalog before accessing it
            auto it = courseCatalog.find(courseCode);
            if (it != courseCatalog.end()) {
                semester->addCourse(courseCode);
            } else {
                std::cout << "Course not found in the catalog.\n";
            }
            return;
        }
    }
    std::cout << "Semester not found.\n";
}
