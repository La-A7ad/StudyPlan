#include "cgpacalc.h"
#include <iostream>

float GPACalculator::getGradePoints(const std::string& letterGrade) const {
    if (letterGrade == "A") return 4.0;
    if (letterGrade == "A-") return 3.7;
    if (letterGrade == "B+") return 3.5;
    if (letterGrade == "B") return 3.3;
    if (letterGrade == "B-") return 3.0;
    if (letterGrade == "C+") return 2.3;
    if (letterGrade == "C") return 2.0;
    if (letterGrade == "C-") return 1.7;
    return 0.0;
}

void GPACalculator::addCourse(const std::string& semester, const Course& course, const std::string& grade) {
    semesters[semester].emplace_back(course, grade);
}

std::pair<float, int> GPACalculator::calculateWeightedGPA(const std::string& semester) const {
    float totalGradePoints = 0;
    int totalCreditHours = 0;

    auto it = semesters.find(semester);
    if (it != semesters.end()) {
        for (const auto& courseInstance : it->second) {
            const Course& course = courseInstance.first;
            const std::string& grade = courseInstance.second;
            float gradePoints = getGradePoints(grade);
            totalGradePoints += gradePoints * course.credits;
            totalCreditHours += course.credits;
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
            const Course& course = courseInstance.first;
            const std::string& grade = courseInstance.second;
            float gradePoints = getGradePoints(grade);
            totalGradePoints += gradePoints * course.credits;
            totalCreditHours += course.credits;
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
            totalCreditHours += courseInstance.first.credits;
        }
    }
    return totalCreditHours;
}

// New methods for managing the GPA calculation environment

void GPACalculator::enterGPACalcEnvironment() {
    std::string command;
    while (true) {
        std::cout << "GPA Calc> ";
        std::cin >> command;
        if (command == "addCourse") {
            addCourseToGPACalc();
        } else if (command == "calculateWeightedGPA") {
            calculateWeightedGPA();
        } else if (command == "calculateCumulativeGPA") {
            calculateCumulativeGPA();
        } else if (command == "listCourses") {
            listGPACalcCourses();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command: " << command << std::endl;
        }
    }
}

void GPACalculator::addCourseToGPACalc() {
    std::string semester, courseID, grade;
    std::cout << "Enter semester: ";
    std::cin >> semester;
    std::cout << "Enter course ID: ";
    std::cin >> courseID;
    std::cout << "Enter grade: ";
    std::cin >> grade;
    
    auto it = Course::courseCatalog.find(courseID);
    if (it != Course::courseCatalog.end()) {
        addCourse(semester, it->second, grade);
    } else {
        std::cout << "Course not found in catalog." << std::endl;
    }
}

void GPACalculator::calculateWeightedGPA() {
    std::string semester;
    std::cout << "Enter semester: ";
    std::cin >> semester;
    auto result = calculateWeightedGPA(semester);
    std::cout << "Weighted GPA: " << result.first << " for " << result.second << " credit hours" << std::endl;
}

void GPACalculator::calculateCumulativeGPA() {
    float gpa = calculateCumulativeGPA();
    std::cout << "Cumulative GPA: " << gpa << std::endl;
}

void GPACalculator::listGPACalcCourses() {
    for (const auto& semester : semesters) {
        std::cout << "Semester: " << semester.first << std::endl;
        for (const auto& courseInstance : semester.second) {
            const Course& course = courseInstance.first;
            const std::string& grade = courseInstance.second;
            std::cout << course.code << ": " << course.title << " (" << course.credits << " credits) - Grade: " << grade << std::endl;
        }
    }
}
