#include "Semester.h"
#include "StudyPlan.h"
#include "Course.h"

bool Semester::canAddCourse(const Course& course, const StudyPlan& studyPlan) {
    for (const auto& semester : studyPlan.getSemesters()) {
        for (const auto& completedCourse : semester.getCourses()) {
            if (std::find(course.getPrerequisites().begin(), course.getPrerequisites().end(), completedCourse.getCode()) != course.getPrerequisites().end()) {
                return true;
            }
        }
    }
    return false;
}

void Semester::addCourse(const Course& course, const StudyPlan& studyPlan) {
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
            return;
        }
    } else if (currentCredits + additionalCredits > 18) {
        std::cout << "Cannot register more than 18 credits.\n";
        return;
    }

    // Add the course
    courses.push_back(course);
    std::cout << "Course " << course.getCode() << " added successfully.\n";
}
