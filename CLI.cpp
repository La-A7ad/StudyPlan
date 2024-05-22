#include "CLI.h"
#include <iostream>
#include <string>


void CLI::displayStudentData() {
    std::cout << "Major: " << student.getMajor() << std::endl;
    std::cout << "Concentration: " << student.getConcentration() << std::endl;
    std::cout << "Year: " << student.getYear() << std::endl;
    std::cout << "GPA: " << student.getcGPA() << std::endl;
    std::cout << "Can Overload: " << (student.getcanOverload() ? "Yes" : "No") << std::endl;
}

void CLI::run() {
    std::string command;
    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        } else if (command == "add_semester") {
            std::string semesterName;
            int maxCredits;
            std::cout << "Enter semester name: ";
            std::getline(std::cin, semesterName);
            std::cout << "Enter maximum credits: ";
            std::cin >> maxCredits;
            std::cin.ignore(); // To ignore the newline character after the integer input
            Semester semester(semesterName, maxCredits);
            studyPlan.addSemester(semester);
            std::cout << "Semester " << semesterName << " added with max credits " << maxCredits << "." << std::endl;
        } else if (command == "add_course") {
            std::string semesterName, courseCode;
            std::cout << "Enter semester name: ";
            std::getline(std::cin, semesterName);
            std::cout << "Enter course code: ";
            std::getline(std::cin, courseCode);
            studyPlan.addCourseToSemester(semesterName, courseCode);
        } else if (command == "list_courses") {
            std::string semesterName;
            std::cout << "Enter semester name: ";
            std::getline(std::cin, semesterName);
            studyPlan.listCoursesInSemester(semesterName);
        } else if (command == "enter_gpa_calc") {
            enterGPACalcEnvironment();
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }
}

void CLI::enterGPACalcEnvironment() {
    std::string command;
    while (true) {
        std::cout << "GPA Calc > ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        } else if (command == "add_course") {
            addCourseToGPACalc();
        } else if (command == "calc_weighted_gpa") {
            calculateWeightedGPA();
        } else if (command == "calc_cumulative_gpa") {
            calculateCumulativeGPA();
        } else if (command == "list_courses") {
            listGPACalcCourses();
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }
}

void CLI::addCourseToGPACalc() {
    std::string semester, courseID, grade;
    std::cout << "Enter semester: ";
    std::getline(std::cin, semester);
    std::cout << "Enter course ID: ";
    std::getline(std::cin, courseID);
    std::cout << "Enter grade: ";
    std::getline(std::cin, grade);
    gpaCalculator.addCourse(semester, courseID, grade);
    std::cout << "Course " << courseID << " added to " << semester << " with grade " << grade << "." << std::endl;
}

void CLI::calculateWeightedGPA() {
    std::string semester;
    std::cout << "Enter semester: ";
    std::getline(std::cin, semester);
    auto [gpa, credits] = gpaCalculator.calculateWeightedGPA(semester);
    std::cout << "Weighted GPA for " << semester << ": " << gpa << " (" << credits << " credits)" << std::endl;
}

void CLI::calculateCumulativeGPA() {
    float gpa = gpaCalculator.calculateCumulativeGPA();
    std::cout << "Cumulative GPA: " << gpa << std::endl;
}

void CLI::listGPACalcCourses() {
    const auto& semesters = gpaCalculator.getSemesters();
    for (const auto& [semester, courses] : semesters) {
        std::cout << "Semester: " << semester << std::endl;
        for (const auto& [courseID, grade] : courses) {
            std::cout << "  Course ID: " << courseID << ", Grade: " << grade << std::endl;
        }
    }
}
