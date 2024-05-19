#include "Course.h"

std::map<std::string, Course> Course::courseCatalog; // Note: No initialization list here


//All courses should be taken from here
static std::map<std::string, Course> courseCatalog = {
    {"CSAI100", {"Introduction to Computational Sciences and AI", 1, {}}},
    {"CSAI101", {"Fundamentals of Programming and Computer Science", 2, {}}},
    {"CSAI102", {"Digital Logic and Computer Architecture", 3, {}}},
    {"CSAI151", {"Object-Oriented Programming", 3, {"CSAI101"}}},
    {"CSAI201", {"Data Structures", 3, {"CSAI151"}}},
    {"CSAI202", {"Introduction to Database Systems", 3, {"CSAI151"}}},
    {"CSAI203", {"Introduction to Software Engineering", 3, {"CSAI101"}}},
    {"CSAI204", {"Operating Systems", 3, {"CSAI201"}}},
    {"CSAI205", {"Fundamentals of Circuits and Electronics", 3, {}}},
    {"CSAI251", {"Algorithm Design and Analysis", 3, {"CSAI201"}}},
    {"CSAI252", {"Introduction to Computer Networks", 3, {}}},
    {"CSAI253", {"Machine Learning", 3, {"CSAI201", "MATH105"}}},
    {"CSAI301", {"Artificial Intelligence", 3, {"CSAI201"}}},
    {"CSAI302", {"Advanced Database Systems", 3, {"CSAI202"}}},
    {"CSAI351", {"Principles and Practices for Secure Computing", 3, {"CSAI201"}}},
    {"CSAI399", {"Internship", 4, {}}},
    {"CSAI498", {"Senior Project - Part 1", 1, {}}},
    {"CSAI499", {"Senior Project - Part 2", 3, {"CSAI498"}}},
    {"DSAI103", {"Data acquisition in data science (ETL)", 3, {"CSAI101"}}}
};



std::vector<std::string> Course::searchCourse(const std::string& courseCodePrefix) {
    std::vector<std::string> results;
    for (const auto& [courseCode, courseDetails] : courseCatalog) {
        if (courseCode.find(courseCodePrefix) == 0) {
            results.push_back(courseCode);
        }
    }
    return results;
}