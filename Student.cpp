#include "Student.h"

Student::Student() : cGPA(0.0), canOverload(false), isOnProbation(false) {}  // Initialize isOnProbation

void Student::setMajor(const std::string& m) {
    major = m;
}

std::string Student::getMajor() const {
    return major;
}

void Student::setConcentration(const std::string& c) {
    concentration = c;
}

std::string Student::getConcentration() const {
    return concentration;
}

void Student::setYear(const std::string& y) {
    year = y;
}

std::string Student::getYear() const {
    return year;
}

void Student::setcGPA(const double g) {
    cGPA = g;
    checkProbationStatus();  // Check probation status whenever GPA is set
}

double Student::getcGPA() const {
    return cGPA;
}

void Student::setcanOverload(const bool o) {
    canOverload = o;
}

bool Student::getcanOverload() const {
    return canOverload;
}

bool Student::setDetails(const json& data) {
    // Implementation from your provided code
    // ...
    return true;  // Ensure there's a return value
}

void Student::checkProbationStatus() {
    isOnProbation = (cGPA < 2.0);
}
