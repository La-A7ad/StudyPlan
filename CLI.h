#ifndef CLI_H
#define CLI_H
#include "StudyPlan.h"
#include "Student.h"
#include "nlohmann/json.hpp"
#include <string>
using json = nlohmann::json;

json loadData(); 

class CLI {
private:
    StudyPlan studyPlan;
    Student studentinput;  // Re-added the student input
    void displayStudentData();      // Re-added json loader function
    Student student;
public:
    CLI() = default;
    void run();
};

#endif
