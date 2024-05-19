#include "CLI.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>

json CLI::loadData() {
    std::string jsonData = R"({
      "Majors": {
        "DSAI": {
          "Concentrations": ["DSAI"]
        },
        "SWD": {
          "Concentrations": ["HCI", "APD", "GD"]
        },
        "IT": {
          "Concentrations": ["NS", "CC"]
        }
      },
      "Years": ["2022", "2023"],
      "canOverload" : false
    })";

    return json::parse(jsonData);
}

void CLI::printSlowly(const std::string& text, unsigned int milliseconds) {
    for (char const &c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }
}

void CLI::run() {
    std::string welcome_message =
        "Welcome to the CSAI Study Plan Editor! Enter 'start' to begin.\n";

    unsigned int delay = 1;
    printSlowly(welcome_message, delay);

    std::string command;

    while (true) {
        std::cout << "-> ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        } else if (command == "start") {
            studentinput.setDetails(loadData());
        } else {
            std::cout << "Unknown command.\n";
        }
    }
}
