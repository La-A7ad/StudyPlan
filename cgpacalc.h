#pragma once
#include "Course.h" // Assuming Course.h includes the necessary Course class
#include <map>
#include <string>
#include <vector>
#include <utility> // Include for std::pair

class GPACalculator {
private:
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> semesters;

    float getGradePoints(const std::string& letterGrade) const;

public:
    void addCourse(const std::string& semester, const std::string& courseID, const std::string& grade);
    std::pair<float, int> calculateWeightedGPA(const std::string& semester) const;
    float calculateCumulativeGPA() const;
    int getTotalCreditHours(const std::string& semester) const;
    const std::map<std::string, std::vector<std::pair<std::string, std::string>>>& getSemesters() const;
};
//test