#include "CLI.h"
#include <iostream>
#include <string>

void CLI::enterGPACalcEnvironment() {
    std::string command;
    while (true) {
        std::cout << "Enter GPA calc command: ";
        std::getline(std::cin, command);

        if (command == "exit_gpa") {
            break;
        } else if (command == "add_course_gpa") {
            addCourseToGPACalc();
        } else if (command == "calc_weighted_gpa") {
            calculateWeightedGPA();
        } else if (command == "calc_cumulative_gpa") {
            calculateCumulativeGPA();
        } else if (command == "list_courses_gpa") {
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
}

void CLI::calculateWeightedGPA() {
    std::string semester;
    std::cout << "Enter semester: ";
    std::getline(std::cin, semester);
    auto result = gpaCalculator.calculateWeightedGPA(semester);
    std::cout << "Weighted GPA for " << semester << ": " << result.first << " with " << result.second << " credit hours." << std::endl;
}

void CLI::calculateCumulativeGPA() {
    float cumulativeGPA = gpaCalculator.calculateCumulativeGPA();
    std::cout << "Cumulative GPA: " << cumulativeGPA << std::endl;
}

void CLI::listGPACalcCourses() {
    const auto& semesters = gpaCalculator.getSemesters();
    for (const auto& semester : semesters) {
        std::cout << "Semester: " << semester.first << std::endl;
        for (const auto& course : semester.second) {
            std::cout << "Course ID: " << course.first << ", Grade: " << course.second << std::endl;
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
