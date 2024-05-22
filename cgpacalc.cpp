#include "cgpacalc.h"

float GPACalculator::getGradePoints(const std::string& letterGrade) const {
    if (letterGrade == "A") return 4.0;
    if (letterGrade == "A-") return 3.7;
    if (letterGrade == "B+") return 3.3;
    if (letterGrade == "B") return 3.0;
    if (letterGrade == "B-") return 2.7;
    if (letterGrade == "C+") return 2.3;
    if (letterGrade == "C") return 2.0;
    if (letterGrade == "C-") return 1.7;
    return 0.0;
}

void GPACalculator::addCourse(const std::string& semester, const std::string& courseID, const std::string& grade) {
    auto it = Course::courseCatalog.find(courseID);
    if (it != Course::courseCatalog.end()) {
        semesters[semester].emplace_back(courseID, grade);
    }
}

std::pair<float, int> GPACalculator::calculateWeightedGPA(const std::string& semester) const {
    float totalGradePoints = 0;
    int totalCreditHours = 0;

    auto it = semesters.find(semester);
    if (it != semesters.end()) {
        for (const auto& courseInstance : it->second) {
            auto courseIt = Course::courseCatalog.find(courseInstance.courseID);
            if (courseIt != Course::courseCatalog.end()) {
                const Course& course = courseIt->second;
                float gradePoints = getGradePoints(courseInstance.grade);
                totalGradePoints += gradePoints * course.getCreditHours();
                totalCreditHours += course.getCreditHours();
            }
        }
    }

    if (totalCreditHours == 0) return { 0.0, 0 };
    return { totalGradePoints / totalCreditHours, totalCreditHours };
}

float GPACalculator::calculateCumulativeGPA() const {
    float totalGradePoints = 0;
    int totalCreditHours = 0;

    for (const auto& semester : semesters) {
        for (const auto& courseInstance : semester.second) {
            auto courseIt = Course::courseCatalog.find(courseInstance.courseID);
            if (courseIt != Course::courseCatalog.end()) {
                const Course& course = courseIt->second;
                float gradePoints = getGradePoints(courseInstance.grade);
                totalGradePoints += gradePoints * course.getCreditHours();
                totalCreditHours += course.getCreditHours();
            }
        }
    }

    if (totalCreditHours == 0) return 0.0;
    return totalGradePoints / totalCreditHours;
}

int GPACalculator::getTotalCreditHours(const std::string& semester) const {
    int totalCreditHours = 0;
    auto it = semesters.find(semester);
    if (it != semesters.end()) {
        for (const auto& courseInstance : it->second) {
            auto courseIt = Course::courseCatalog.find(courseInstance.courseID);
            if (courseIt != Course::courseCatalog.end()) {
                totalCreditHours += courseIt->second.getCreditHours();
            }
        }
    }
    return totalCreditHours;
}

const std::map<std::string, std::vector<std::pair<std::string, std::string>>>& GPACalculator::getSemesters() const {
    return semesters;
}
