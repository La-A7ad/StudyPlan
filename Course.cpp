#include "Course.h"

std::map<std::string, Course> Course::courseCatalog = {
    {"CSAI100", {"Introduction to Computational Sciences and AI", 1, {}}},
    // Add other courses here
};

Course::Course(std::string name, int credits, std::vector<std::string> prerequisites)
    : name(std::move(name)), credits(credits), prerequisites(std::move(prerequisites)) {}

std::vector<std::string> Course::searchCourse(const std::string& courseCodePrefix) {
    std::vector<std::string> results;
    for (const auto& [courseCode, courseDetails] : courseCatalog) {
        if (courseCode.find(courseCodePrefix) == 0) {
            results.push_back(courseCode);
        }
    }
    return results;
}

const std::vector<std::string>& Course::getPrerequisites() const {
    return prerequisites;
}

const std::string& Course::getCode() const {
    static std::string empty;
    for (const auto& [courseCode, courseDetails] : courseCatalog) {
        if (&courseDetails == this) {
            return courseCode;
        }
    }
    return empty;
}

int Course::getCredits() const {
    return credits;
}
