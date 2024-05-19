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
    bool isOnProbation;

public:
    // Remove constructor
    bool validateInput(const std::string& input, const json& validOptions, const std::string& type);
    bool setDetails(const json& data);

    void setMajor(const std::string& gotmajor);
    std::string getMajor() const;

    void setConcentration(const std::string& gotconcentration);
    std::string getConcentration() const;

    void setyear(const std::string& gotyear);
    std::string getyear() const;

    void setcGPA(const double gotcGPA);
    double getcGPA() const;

    void setcanOverload(const bool gotsetcanOverload);
    bool getcanOverload() const;

    void checkProbationStatus();
};

#endif
