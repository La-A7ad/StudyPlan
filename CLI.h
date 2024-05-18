#pragma once
#include "Student.h"
#include "StudyPlan.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class CLI {
private:
    Student studentinput;
    StudyPlan studyPlan; // Add a StudyPlan member

    static void printSlowly(const std::string &text);
    void handleCommand(const std::string& command);

public:
    void run();
};

json studentJSON();
