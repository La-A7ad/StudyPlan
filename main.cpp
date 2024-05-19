#include <iostream>
#include "CLI.h"
#include "Student.h"



int main() {
    Student student("Computer Science", "Freshman", "AI", 3.5, true);
    CLI cli(student);
     std::string command;
    while (std::getline(std::cin, command)) {
        cli.handleCommand(command);
    }
    return 0;
}