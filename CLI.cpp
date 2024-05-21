#include "CLI.h"
#include <iostream>
#include <string>

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
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }
}

void CLI::displayStudentData() {
    std::cout << "Major: " << student.getMajor() << std::endl;
    std::cout << "Concentration: " << student.getConcentration() << std::endl;
    std::cout << "Year: " << student.getYear() << std::endl;
    std::cout << "GPA: " << student.getcGPA() << std::endl;
    std::cout << "Can Overload: " << (student.getcanOverload() ? "Yes" : "No") << std::endl;
}
