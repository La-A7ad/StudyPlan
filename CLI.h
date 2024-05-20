#ifndef CLI_H
#define CLI_H

#include "Student.h"
#include "StudyPlan.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

json loadData();  // Declare the loadData function

class CLI {
private:
    Student studentinput;
    StudyPlan studyPlan;

    void displayStudentData();

public:
    CLI();  // Declare the constructor explicitly
    void run();
};

#endif
