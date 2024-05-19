#ifndef CLI_H
#define CLI_H

#include "Student.h"
#include "StudyPlan.h"
#include <memory>

class CLI {
private:
    std::unique_ptr<Student> studentinput;
    std::unique_ptr<StudyPlan> studyPlan;

public:
    CLI(); // Default constructor

    void handleCommand(const std::string& command);
    void searchCourse(const std::string& courseCodePrefix);
    void initializeStudent(); // Declare the initializeStudent method
};

#endif
