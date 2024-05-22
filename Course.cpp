#include "Course.h"

// Static member initialization
std::map<std::string, Course> Course::courseCatalog = {
    {"CSAI100", Course("CSAI100", "Introduction to Computational Sciences and AI", 1, {})},
    {"CSAI101", Course("CSAI101", "Fundamentals of Programming and Computer Science", 2, {})},
    {"CSAI102", Course("CSAI102", "Digital Logic and Computer Architecture", 3, {})},
    {"CSAI151", Course("CSAI151", "Object-Oriented Programming", 3, {"CSAI101"})},
    {"CSAI201", Course("CSAI201", "Data Structures", 3, {"CSAI151"})},
    {"CSAI202", Course("CSAI202", "Introduction to Database Systems", 3, {"CSAI151"})},
    {"CSAI203", Course("CSAI203", "Introduction to Software Engineering", 3, {"CSAI101"})},
    {"CSAI204", Course("CSAI204", "Operating Systems", 3, {"CSAI201"})},
    {"CSAI205", Course("CSAI205", "Fundamentals of Circuits and Electronics", 3, {})},
    {"CSAI251", Course("CSAI251", "Algorithm Design and Analysis", 3, {"CSAI201"})},
    {"CSAI252", Course("CSAI252", "Introduction to Computer Networks", 3, {})},
    {"CSAI253", Course("CSAI253", "Machine Learning", 3, {"CSAI201", "MATH105"})},
    {"CSAI301", Course("CSAI301", "Artificial Intelligence", 3, {"CSAI201"})},
    {"CSAI302", Course("CSAI302", "Advanced Database Systems", 3, {"CSAI202"})},
    {"CSAI351", Course("CSAI351", "Principles and Practices for Secure Computing", 3, {"CSAI201"})},
    {"CSAI399", Course("CSAI399", "Internship", 4, {})},
    {"CSAI498", Course("CSAI498", "Senior Project - Part 1", 1, {})},
    {"CSAI499", Course("CSAI499", "Senior Project - Part 2", 3, {"CSAI498"})},
    {"DSAI103", Course("DSAI103", "Data acquisition in data science (ETL)", 3, {"CSAI101"})},
    {"DSAI104", Course("DSAI104", "Knowledge Representation and Reasoning", 2, {"CSAI101"})}
};

Course::Course(std::string code, std::string title, int creditHours, std::vector<std::string> prerequisites)
    : code(code), title(title), creditHours(creditHours), prerequisites(prerequisites) {}


const std::string& Course::getCode() const {
    return code;
}

const std::string& Course::getTitle() const {
    return title;
}

int Course::getCreditHours() const {
    return creditHours;
}

const std::vector<std::string>& Course::getPrerequisites() const {
    return prerequisites;
}

std::vector<std::string> Course::searchCourse(const std::string& courseCodePrefix) {
    std::vector<std::string> results;
    for (const auto& [courseCode, courseDetails] : courseCatalog) {
        if (courseCode.find(courseCodePrefix) == 0) {
            results.push_back(courseCode);
        }
    }
    return results;
}