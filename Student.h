#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

json loadData();

class Student {
private:
    std::string major;
    std::string year;
    std::string concentration;
    double cGPA;
    bool canOverload;

public:
    Student() : cGPA(0.0), canOverload(false) {}

    void setMajor(const std::string& m) { major = m; }
    void setYear(const std::string& y) { year = y; }
    void setConcentration(const std::string& c) { concentration = c; }
    void setCgpa(double g) { cGPA = g; }
    void setCanOverload(bool o) { canOverload = o; }

    bool setDetails(const json& data);

    std::string getMajor() const { return major; }
    std::string getConcentration() const { return concentration; }
    std::string getYear() const { return year; }
    double getcGPA() const { return cGPA; }
    bool getcanOverload() const { return canOverload; }
};

#endif


//test