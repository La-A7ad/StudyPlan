#ifndef CLI_H
#define CLI_H

#include "Student.h"
#include "StudyPlan.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

json loadData();

class CLI {
private:
    Student studentinput;
    StudyPlan studyPlan;

    void displayStudentData();

public:
    CLI();  // Constructor
    void run();
};

#endif
