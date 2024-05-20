#ifndef CLI_H
#define CLI_H

#include "Student.h"
#include "StudyPlan.h"
#include "nlohmann/json.hpp"
#include <string>

using json = nlohmann::json;

class CLI {
private:
    Student student;
    StudyPlan studyPlan;

    void printSlowly(const std::string& text, unsigned int milliseconds);
    json loadData();

public:
    CLI();

    void run();
    void displayStudentData();
    void searchCourses();
    void addSemester();
    void addCourseToSemester();
};

#endif
