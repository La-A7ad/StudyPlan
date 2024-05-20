#include "CLI.h"
#include <iostream>
#include <string>


CLI::CLI() : studentinput() { }

json CLI::loadData() {
    std::string jsonData = R"({
      "Majors": {
        "DSAI": {
          "Concentrations": ["DSAI"]
        },
        "SWD": {
          "Concentrations": ["HCI", "APD", "GD"]
        },
        "IT": {
          "Concentrations": ["NS", "CC"]
        }
      },
      "Years": ["2022", "2023"],
      "canOverload": false
    })";

    return json::parse(jsonData);
}

void CLI::displayStudentData() {
    std::cout << "Major: " << studentinput.getMajor() << "\n"
              << "Concentration: " << studentinput.getConcentration() << "\n"
              << "Year: " << studentinput.getYear() << "\n"
              << "GPA: " << studentinput.getcGPA() << "\n"
              << "Can Overload: " << (studentinput.getcanOverload() ? "Yes" : "No") << "\n";
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
            std::string prefix;
            std::cout << "Enter course code prefix: ";
            std::getline(std::cin, prefix);
            auto results = Course::searchCourse(prefix);
            for (const auto& courseCode : results) {
                std::cout << courseCode << "\n";
            }
        } else if (command == "add_semester") {
            std::string semesterName;
            int maxCredits;
            std::cout << "Enter semester name: ";
            std::getline(std::cin, semesterName);
            std::cout << "Enter maximum credits: ";
            std::cin >> maxCredits;
            std::cin.ignore();  // to ignore the newline character after integer input
            studyPlan.addSemester(Semester(semesterName, maxCredits));
            std::cout << "Semester " << semesterName << " added with max credits " << maxCredits << ".\n";
        } else if (command == "add_course") {
            std::string semesterName, courseCode;
            std::cout << "Enter semester name: ";
            std::getline(std::cin, semesterName);
            std::cout << "Enter course code: ";
            std::getline(std::cin, courseCode);
            studyPlan.addCourseToSemester(semesterName, courseCode);
        } else {
            std::cout << "Unknown command.\n";
        }
    }
}
