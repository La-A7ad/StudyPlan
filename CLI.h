#ifndef CLI_H
#define CLI_H

#include "StudyPlan.h"
#include "Student.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

class CLI {
private:
    StudyPlan studyPlan;
    Student studentinput;  // Re-added the student input
    void displayStudentData();
    json loadData();       // Re-added json loader function
    Student student;
public:
    CLI();                 // Default constructor removed
    void run();
};

#endif
