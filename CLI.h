#ifndef CLI_H
#define CLI_H

#include "Student.h"
#include <string>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class CLI {
private:
    Student studentinput;
    void printSlowly(const std::string& text, unsigned int milliseconds);
    json loadData();

public:
    void run();
};

#endif
