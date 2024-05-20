#include "Student.h"
#include <iostream>
#include <algorithm>
#include <limits>

Student::Student() : cGPA(0.0), canOverload(false) {}

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
}

void Student::checkProbationStatus() {
    isOnProbation = (cGPA < 2.0);
}
