#include "StudyPlan.h"
#include <iostream>

void StudyPlan::addSemester(std::string name, std::string type) {
    if (type == "Fall") {
        semesters.push_back(new FallSemester(name, true)); 
    } else if (type == "Spring") {
        semesters.push_back(new SpringSemester(name, true)); 
    } else if (type == "Summer") {
        semesters.push_back(new SummerSemester(name));
    } else {
        std::cout << "Invalid semester type.\n";
        return;
    }
    std::cout << "Semester " << name << " added.\n";
}

void StudyPlan::addCourseToSemester(const std::string& semesterName, const std::string& courseTitle) {
    for (auto semester : semesters) {
        if (semester->getSemesterName() == semesterName) {
            semester->addCourse(courseTitle);
            return;
        }
    }
    std::cout << "Semester not found.\n";
}
