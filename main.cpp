#include "CLI.h"
#include <iostream>

int main() {
    CLI cli;

    // Print logo or any initialization messages
    std::cout << "Welcome to the CSAI Study Plan Editor! Enter 'start'." << std::endl;

    std::string command;
    while (true) {
        std::cout << "-> ";
        if (!std::getline(std::cin, command)) break;
        cli.handleCommand(command);
    }

    return 0;
}
