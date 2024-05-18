#include "Student.h"
#include <iostream>
#include <algorithm>

bool Student::validateInput(const std::string& input, const json& validOptions, const std::string& type) {
    if (type == "major" && validOptions["Majors"].contains(input)) {
        return true;
    } else if (type == "concentration" && std::find(validOptions["Majors"][major]["Concentrations"].begin(),
                                                    validOptions["Majors"][major]["Concentrations"].end(), input) != validOptions["Majors"][major]["Concentrations"].end()) {
        return true;
    } else if (type == "year" && std::find(validOptions["Years"].begin(), validOptions["Years"].end(), input) != validOptions["Years"].end()) {
        return true;
    }
    return false;
}

bool Student::setDetails(const json& data) {
    std::cout << "Enter your major: ";
    std::cin >> major;
    if (!validateInput(major, data, "major")) {
        std::cout << "Invalid major entered.\n";
        return false;
    }

    std::cout << "Enter your concentration: ";
    std::cin >> concentration;
    if (!validateInput(concentration, data, "concentration")) {
        std::cout << "Invalid concentration entered.\n";
        return false;
    }

    std::cout << "Enter your year: ";
    std::cin >> year;
    if (!validateInput(year, data, "year")) {
        std::cout << "Invalid year entered.\n";
        return false;
    }

    std::cout << "Enter your cGPA: ";
    std::cin >> cGPA;
    if (cGPA >= 3.0) {
        std::cout << "Are you able to overload? (1 for yes, 0 for no): ";
        std::cin >> canOverload;
    }

    std::cout << "Student configured successfully.\n";
    return true;
}

void Student::setMajor(const std::string& gotmajor) {
    major = gotmajor;
}

std::string Student::getMajor() const {
    std::cout << "Major: " << major << std::endl;
    return major;
}

void Student::setConcentration(const std::string& gotconcentration) {
    concentration = gotconcentration;
}

std::string Student::getConcentration() const {
    std::cout << "Concentration: " << concentration << std::endl;
    return concentration;
}

void Student::setyear(const std::string& gotyear) {
    year = gotyear;
}

std::string Student::getyear() const {
    std::cout << "Year: " << year << std::endl;
    return year;
}

void Student::setcGPA(const double gotcGPA) {
    cGPA = gotcGPA;
}

std::string Student::getcGPA() const {
    std::string stringcGPA = std::to_string(cGPA);
    std::cout << "cGPA: " << stringcGPA << std::endl;
    return stringcGPA;
}

void Student::setcanOverload(const bool gotsetcanOverload) {
    canOverload = gotsetcanOverload;
}

bool Student::getcanOverload() const {
    if (canOverload) {
        std::cout << "Overload status: Yes" << std::endl;
        return true;
    } else {
        std::cout << "Overload status: No" << std::endl;
        return false;
    }
}
