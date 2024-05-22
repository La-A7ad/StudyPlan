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

void CLI::enterGPACalcEnvironment() {
    std::string command;
    while (true) {
        std::cout << "Enter GPA Calc command: ";
        std::getline(std::cin, command);

        if (command == "exit_gpa") {
            break;
        } else if (command == "add_gpa_course") {
            addCourseToGPACalc();
        } else if (command == "calculate_weighted_gpa") {
            calculateWeightedGPA();
        } else if (command == "calculate_cumulative_gpa") {
            calculateCumulativeGPA();
        } else if (command == "list_gpa_courses") {
            listGPACalcCourses();
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }
}

void CLI::addCourseToGPACalc() {
    std::string semesterName, courseCode, grade;
    std::cout << "Enter semester name: ";
    std::getline(std::cin, semesterName);
    std::cout << "Enter course code: ";
    std::getline(std::cin, courseCode);
    std::cout << "Enter grade: ";
    std::getline(std::cin, grade);
    gpaCalculator.addCourse(semesterName, courseCode, grade);
    std::cout << "Course " << courseCode << " with grade " << grade << " added to semester " << semesterName << "." << std::endl;
}

void CLI::calculateWeightedGPA() {
    std::string semesterName;
    std::cout << "Enter semester name: ";
    std::getline(std::cin, semesterName);
    auto result = gpaCalculator.calculateWeightedGPA(semesterName);
    std::cout << "Weighted GPA for semester " << semesterName << " is " << result.first << " with total credit hours " << result.second << "." << std::endl;
}

void CLI::calculateCumulativeGPA() {
    float cumulativeGPA = gpaCalculator.calculateCumulativeGPA();
    std::cout << "Cumulative GPA is " << cumulativeGPA << "." << std::endl;
}

void CLI::listGPACalcCourses() {
    for (const auto& semester : gpaCalculator.getSemesters()) {
        std::cout << "Courses in " << semester.first << " semester:" << std::endl;
        for (const auto& courseInstance : semester.second) {
            std::cout << courseInstance.getCourseCode() << ": " << courseInstance.getGrade() << std::endl;
        }
    }
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
        } else if (command == "gpa_calc") {
            enterGPACalcEnvironment();
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }
}