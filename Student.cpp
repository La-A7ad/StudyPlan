#include "Student.h"
#include <iostream>
#include <limits>
#include <algorithm>

bool Student::setDetails(const json& data) {
    while (true) {
        std::cout << "Enter your major: ";
        if (!(std::cin >> major)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        std::cout << "Enter your concentration: ";
        if (!(std::cin >> concentration)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        std::cout << "Enter your year: ";
        if (!(std::cin >> year)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        auto majors = data["Majors"];
        if (majors.contains(major) &&
            std::find(majors[major]["Concentrations"].begin(), majors[major]["Concentrations"].end(), concentration) != majors[major]["Concentrations"].end()) {
            auto years = data["Years"];
            if (std::find(years.begin(), years.end(), year) != years.end()) {
                break;
            } else {
                std::cout << "Invalid year entered. Please try again.\n";
                continue;
            }
        } else {
            std::cout << "Invalid major or concentration entered. Please try again.\n";
            continue;
        }
    }

    std::cout << "Enter your cGPA: ";
    std::cin >> cGPA;

    if (cGPA > 3.0) {
        std::cout << "Are you able to overload? (1 for yes, 0 for no): ";
        std::cin >> canOverload;
    }

    std::cout << "Student configured successfully." << std::endl;
    return true;
}

//test