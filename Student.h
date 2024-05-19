#pragma once
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
    bool isOnProbation;

public:
    // Constructor
    Student(const std::string& maj, const std::string& yr, const std::string& conc, double gpa, bool overloadPerm)
        : major(maj), year(yr), concentration(conc), cGPA(gpa), canOverload(overloadPerm) {
        checkProbationStatus();
    }

    // Input validation
    bool validateInput(const std::string& input, const json& validOptions, const std::string& type);

    // Set student details
    bool setDetails(const json& data);

    // Getters and setters for major
    void setMajor(const std::string& gotmajor);
    std::string getMajor() const;

    // Getters and setters for concentration
    void setConcentration(const std::string& gotconcentration);
    std::string getConcentration() const;

    // Getters and setters for year
    void setyear(const std::string& gotyear);
    std::string getyear() const;

    // Getters and setters for cGPA
    void setcGPA(const double gotcGPA);
    double getcGPA() const;

    // Getters and setters for canOverload
    void setcanOverload(const bool gotsetcanOverload);
    bool getcanOverload() const;

    // Check probation status
    void checkProbationStatus();
};
