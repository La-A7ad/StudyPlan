#include "StudyPlan.h"
#include "Course.h"
#include <iostream>

void StudyPlan::addCourseToSemester(const std::string& semesterName, const std::string& courseCode) {
    for (auto& semester : semesters) {
        if (semester->getSemesterName() == semesterName) {
            auto it = Course::courseCatalog.find(courseCode);
            if (it != Course::courseCatalog.end()) {
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
    return student->getcGPA() < 2.0; // Use getcGPA()
}

bool StudyPlan::canOverload() const {
    return student->getcanOverload(); // Use getcanOverload()
}
