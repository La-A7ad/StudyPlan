#include "Student.h"
#include <iostream>

// Validate input based on a JSON array of valid options
bool Student::validateInput(const std::string& input, const json& validOptions, const std::string& type) {
    if (validOptions.contains(input)) {
        return true;
    } else {
        std::cout << "Invalid " << type << " provided.\n";
        return false;
    }
}

// Set student details based on JSON data
bool Student::setDetails(const json& data) {
    if (data.contains("major") && data.contains("year") && data.contains("concentration") && 
        data.contains("cGPA") && data.contains("canOverload")) {

        setMajor(data["major"]);
        setyear(data["year"]);
        setConcentration(data["concentration"]);
        setcGPA(data["cGPA"]);
        setcanOverload(data["canOverload"]);
        checkProbationStatus();

        return true;
    } else {
        std::cout << "Invalid data provided.\n";
        return false;
    }
}

// Setters and getters for major
void Student::setMajor(const std::string& gotmajor) {
    major = gotmajor;
}
std::string Student::getMajor() const {
    return major;
}

// Setters and getters for concentration
void Student::setConcentration(const std::string& gotconcentration) {
    concentration = gotconcentration;
}
std::string Student::getConcentration() const {
    return concentration;
}

// Setters and getters for year
void Student::setyear(const std::string& gotyear) {
    year = gotyear;
}
std::string Student::getyear() const {
    return year;
}

// Setters and getters for cGPA
void Student::setcGPA(const double gotcGPA) {
    cGPA = gotcGPA;
    checkProbationStatus();
}
double Student::getcGPA() const {
    return cGPA;
}

// Setters and getters for canOverload
void Student::setcanOverload(const bool gotsetcanOverload) {
    canOverload = gotsetcanOverload;
}
bool Student::getcanOverload() const {
    return canOverload;
}

// Check probation status
void Student::checkProbationStatus() {
    isOnProbation = (cGPA < 2.0);
}
