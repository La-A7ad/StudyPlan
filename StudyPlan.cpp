#include "StudyPlan.h"
#include <iostream>

void StudyPlan::addSemester(const Semester& semester) {
    semesters.push_back(semester);
}

void StudyPlan::addCourseToSemester(const std::string& semesterName, const std::string& courseCode) {
    auto it = Course::courseCatalog.find(courseCode);
    if (it == Course::courseCatalog.end()) {
        std::cout << "Course not found.\n";
        return;
    }

    for (auto& semester : semesters) {
        if (semester.getSemesterName() == semesterName) {
            semester.addCourse(it->second, *this);
            return;
        }
    }
    std::cout << "Semester not found.\n";
}

bool StudyPlan::isStudentOnProbation() const {
    return student.getcGPA() < 2.0;
}

bool StudyPlan::canOverload() const {
    return student.getcanOverload();
}

std::vector<Semester>& StudyPlan::getSemesters() {
    return semesters;
}
