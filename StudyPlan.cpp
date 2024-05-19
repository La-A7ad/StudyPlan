#include "StudyPlan.h"
#include <iostream>

void StudyPlan::addCourseToSemester(const std::string& semesterName, const std::string& courseCode) {
    for (auto semester : semesters) {
        if (semester->getSemesterName() == semesterName) {
            auto it = courseCatalog.find(courseCode);
            if (it != courseCatalog.end()) {
                semester->addCourse(it->second, *this);
            } else {
                std::cout << "Course not found in the catalog.\n";
            }
            return;
        }
    }
    std::cout << "Semester not found.\n";
}

void StudyPlan::addSemester(Semester& newSemester) {
    semesters.push_back(&newSemester);
}

bool StudyPlan::isStudentOnProbation() const {
    return student->getGPA() < 2.0;
}

bool StudyPlan::canOverload() const {
    return student->canOverload();
}
