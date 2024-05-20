#include "CLI.h"
#include "Course.h"
#include "Student.h" // Include necessary headers for Student and loadData
#include <iostream>

CLI::CLI() {
    // Constructor implementation if needed
}

void CLI::displayStudentData() {
    std::cout << "Major: " << studentinput.getMajor() << std::endl;
    std::cout << "Concentration: " << studentinput.getConcentration() << std::endl;
    std::cout << "Year: " << studentinput.getYear() << std::endl;
    std::cout << "GPA: " << studentinput.getcGPA() << std::endl;
    std::cout << "Can Overload: " << (studentinput.getcanOverload() ? "Yes" : "No") << std::endl;
}

void CLI::run() {
    std::string command;
    while (true) {
        std::cout << "-> ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        } else if (command == "start") {
            studentinput.setDetails(loadData());
        } else if (command == "student") {
            displayStudentData();
        } else if (command == "search") {
            std::string courseCode;
            std::cout << "Enter course code prefix: ";
            std::cin >> courseCode;
            std::vector<std::string> results = Course::searchCourse(courseCode);
            for (const auto& result : results) {
                std::cout << result << std::endl;
            }
        } else if (command == "add_semester") {
            std::string semesterName;
            int maxCredits;
            std::cout << "Enter semester name: ";
            std::cin >> semesterName;
            std::cout << "Enter maximum credits: ";
            std::cin >> maxCredits;
            Semester newSemester(semesterName, maxCredits);
            studyPlan.addSemester(newSemester);
            std::cout << "Semester " << semesterName << " added with max credits " << maxCredits << ".\n";
        } else if (command == "add_course") {
            std::string semesterName, courseCode;
            std::cout << "Enter semester name: ";
            std::cin >> semesterName;
            std::cout << "Enter course code: ";
            std::cin >> courseCode;
            studyPlan.addCourseToSemester(semesterName, courseCode);
        } else {
            std::cout << "Unknown command.\n";
        }
    }
}
