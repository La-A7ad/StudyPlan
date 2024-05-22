#pragma once
#include "Course.h"
#include <map>
#include <string>
#include <vector>
#include <utility> // Include for std::pair

class GPACalculator {
private:
    std::map<std::string, std::vector<std::pair<Course, std::string>>> semesters;

    float getGradePoints(const std::string& letterGrade) const;

public:
    void addCourse(const std::string& semester, const Course& course, const std::string& grade);
    std::pair<float, int> calculateWeightedGPA(const std::string& semester) const;
    float calculateCumulativeGPA() const;
    int getTotalCreditHours(const std::string& semester) const;

    // New methods for managing the GPA calculation environment
    void enterGPACalcEnvironment();
    void addCourseToGPACalc();
    void calculateWeightedGPA();
    void calculateCumulativeGPA();
    void listGPACalcCourses();
};
