#include "CLI.h"
#include <iostream>
#include <string>

CLI::CLI() {
    std::cout << "CLI Constructor: Initializing student..." << std::endl;
    initializeStudent();
    std::cout << "CLI Constructor: Student initialized successfully." << std::endl;
}

void CLI::initializeStudent() {
    std::string major, year, concentration;
    double gPA;
    bool overload;

    std::cout << "Enter major: ";
    std::cin >> major;
    std::cout << "Enter year: ";
    std::cin >> year;
    std::cout << "Enter concentration: ";
    std::cin >> concentration;
    std::cout << "Enter GPA: ";
    std::cin >> gPA;
    std::cout << "Can overload (1 for yes, 0 for no): ";
    std::cin >> overload;

    studentinput = std::make_unique<Student>();
    studentinput->setMajor(major);
    studentinput->setyear(year);
    studentinput->setConcentration(concentration);
    studentinput->setcGPA(gPA);
    studentinput->setcanOverload(overload);
    studentinput->checkProbationStatus();

    studyPlan = std::make_unique<StudyPlan>(studentinput.get());
}

void CLI::handleCommand(const std::string& command) {
    std::cout << "Handling command: " << command << std::endl;
    if (command == "addSemester") {
        std::string name, type;
        std::cout << "Enter semester name: ";
        std::cin >> name;
        std::cout << "Enter semester type: ";
        std::cin >> type;
        Semester* newSemester = new Semester(name, 18); // Assuming default maxCredits = 18
        studyPlan->addSemester(*newSemester);
    } else if (command.substr(0, 6) == "search") {
        std::string courseCodePrefix = command.substr(7);
        searchCourse(courseCodePrefix);
    } else if (command == "addCourse") {
        std::string semesterName, courseCode;
        std::cout << "Enter semester name: ";
        std::cin >> semesterName;
        std::cout << "Enter course code: ";
        std::cin >> courseCode;
        studyPlan->addCourseToSemester(semesterName, courseCode);
    } else {
        std::cout << "Unknown command.\n";
    }
}

void CLI::searchCourse(const std::string& courseCodePrefix) {
    std::vector<std::string> results = Course::searchCourse(courseCodePrefix);
    for (const std::string& courseCode : results) {
        std::cout << courseCode << "\n";
    }
}

