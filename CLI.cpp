// CLI.cpp
#include "CLI.h"
#include <iostream>

json loadData() {
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
    std::cout << "Major: " << student.getMajor() << std::endl;
    std::cout << "Concentration: " << student.getConcentration() << std::endl;
    std::cout << "Year: " << student.getYear() << std::endl;
    std::cout << "GPA: " << student.getcGPA() << std::endl;
    std::cout << "Can Overload: " << (student.getcanOverload() ? "Yes" : "No") << std::endl;
}

void CLI::run() {
    std::string command;
    while (true) {
        std::cout << "-> ";
        std::getline(std::cin, command);
        
        if (command == "exit") {
            break;
        } else if (command == "start") {
            student.setDetails(loadData());
        } else if (command == "student") {
            displayStudentData();
        } else if (command == "add_semester") {
            std::string semesterName;
            int maxCredits;
            std::cout << "Enter semester name: ";
            std::cin >> semesterName;
            std::cout << "Enter maximum credits: ";
            std::cin >> maxCredits;
            studyPlan.addSemester(Semester(semesterName, maxCredits));
            std::cout << "Semester " << semesterName << " added with max credits " << maxCredits << "." << std::endl;
        } else if (command == "add_course") {
            std::string semesterName, courseCode;
            std::cout << "Enter semester name: ";
            std::cin >> semesterName;
            std::cout << "Enter course code: ";
            std::cin >> courseCode;
            studyPlan.addCourseToSemester(semesterName, courseCode);
            std::cout << "Course " << courseCode << " added to semester " << semesterName << "." << std::endl;
        } else if (command.rfind("search ", 0) == 0) {
            std::string prefix = command.substr(7);
            auto results = Course::searchCourse(prefix);
            for (const auto& result : results) {
                std::cout << result << std::endl;
            }
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }
}
