#include "Student.h"
#include <iostream>
#include <algorithm>
#include <limits>

Student::Student() : cGPA(0.0), canOverload(false) {}

void Student::setMajor(const std::string& m) { major = m; }
void Student::setYear(const std::string& y) { year = y; }
void Student::setConcentration(const std::string& c) { concentration = c; }
void Student::setCgpa(double g) { cGPA = g; }
void Student::setCanOverload(bool o) { canOverload = o; }

double Student::getcGPA() const { return cGPA; } // Getter implementation
bool Student::getcanOverload() const { return canOverload; } // Getter implementation

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

    if (validateMajorAndConcentration(major, concentration, data) && validateYear(year, data)) {
        if (cGPA > 3.0) {
            std::cout << "Are you able to overload? (1 for yes, 0 for no): ";
            std::cin >> canOverload;
        }
        std::cout << "Student configured successfully." << std::endl;
        return true;
    }
    std::cout << "Failed to configure student with provided data." << std::endl;
    return false;
}

bool Student::validateMajorAndConcentration(const std::string& major, const std::string& concentration, const json& data) {
    auto majors = data["Majors"];
    if (majors.contains(major) &&
        std::find(majors[major]["Concentrations"].begin(), majors[major]["Concentrations"].end(), concentration) != majors[major]["Concentrations"].end()) {
        return true;
    }
    std::cout << "Invalid major or concentration entered." << std::endl;
    return false;
}

bool Student::validateYear(const std::string& year, const json& data) {
    auto years = data["Years"];
    if (std::find(years.begin(), years.end(), year) != years.end()) {
        return true;
    }
    std::cout << "Invalid year entered." << std::endl;
    return false;
}
