#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Student {
private:
    std::string major;
    std::string year;
    std::string concentration;
    double cGPA;
    bool canOverload;

public:
    Student();
    bool setDetails(const json& data);
    void setMajor(const std::string& m);
    void setYear(const std::string& y);
    void setConcentration(const std::string& c);
    void setCgpa(double g);
    void setCanOverload(bool o);
    double getcGPA() const; // Getter for cGPA
    bool getcanOverload() const; // Getter for canOverload
    bool validateMajorAndConcentration(const std::string& major, const std::string& concentration, const json& data);
    bool validateYear(const std::string& year, const json& data);
};

#endif
