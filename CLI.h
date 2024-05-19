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
    
public: 
    CLI(Student student) : studentinput(student), studyPlan(&studentinput) {}
    void handleCommand(const std::string& command);
    void searchCourse(const std::string& courseCodePrefix);

 
    void run();
     
  
};

json studentJSON();
