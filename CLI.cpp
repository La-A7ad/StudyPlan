#include "CLI.h"
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>

json studentJSON() {
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

    json j = json::parse(jsonData);
    return j;
}

void CLI::printSlowly(const std::string &text) {
    for (char const &c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void CLI::handleCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string cmd;
    iss >> cmd;
    // Command handling logic here
}

void CLI::run() {
    std::string Zewail_logo =
                "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡤⡄⠀⠀⢫⣯⡇⡤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡠⠔⡆⡟⢣⠀⣰⢺⡅⣇⠟⣇⡤⡄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡳⣄⢀⡻⢹⣆⣿⢸⡸⣨⠁⠛⠚⠂⠨⢤⣭⣰⡟⠦⡍⢳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⡉⡵⠺⣿⠽⠓⠉⠉⠁⠀⠀⠀⠀⠀⠈⠛⠚⠈⠉⠒⢬⢁⡑⡆⠀⠀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠖⣿⠿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠢⠔⣿⠲⡀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠞⣡⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣌⠢⡀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⠀⡰⢁⡜⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢢⠈⢄⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⡰⢁⠎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⡼⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠱⡈⢧⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⡰⠁⡎⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣦⡀⠀⣠⣾⢿⣻⠁⠈⠻⣷⢄⠀⠀⢀⣤⣄⠀⠀⠀⠀⠀⠀⠀⢱⠈⢇⠀\n"
                "⠀⠀⠀⠀⠀⢠⠃⡸⠀⠀⠀⠀⠀⠀⠀⢀⣴⡿⣯⠏⠙⢾⣟⢁⣮⠇⠀⠀⠀⠈⠳⣕⢾⣿⣻⠻⣷⣄⠀⠀⠀⠀⠀⠀⢇⠘⡄\n"
                "⠀⠀⠀⠀⠀⡸⢀⡇⠀⠀⠀⠀⠀⠀⢀⣴⡿⠋⡸⡞⠀⠀⠈⠻⣟⢞⠀⠀⠀⠀⠀⠀⠈⠳⣝⢇⠀⠈⠻⣷⢄⠀⠀⠀⠀⠸⡀⢇\n"
                "⠀⠀⠀⠀⠀⡇⢸⠀⠀⠀⠀⣀⢴⡿⣫⣴⣿⡷⡃⠀⠀⠀⠀⠈⠳⣵⣶⢿⣦⢀⠀⠀⠀⠈⠳⣕⢄⠀⠈⠳⣕⢄⠀⠀⠀⡇⢸\n"
                "⠀⠀⠀⠀⠀⣗⣚⣒⣒⣒⣚⣓⣓⣚⣻⣻⠃⠙⢮⣓⣒⣒⣒⣒⣚⣛⣟⡎⠈⠢⣑⣒⣒⣒⣒⣚⣳⣕⣒⣒⣚⣳⣕⣒⣒⣓⣺\n"
                "⠀⠀⠀⠀⠀⣤⡒⢲⡖⣶⡖⠒⢒⣤⡦⡤⣶⣄⠀⣠⣦⢦⠀⠀⡖⡶⡶⡄⠀⠀⠀⢀⣤⡶⢶⣄⣰⢦⣔⡖⢐⠒⡢⣄⠀⢠⣷\n"
                "⠀⠀⠀⠀⠀⠉⢀⢞⡜⠁⠀⣥⣤⡍⢱⢹⣼⡜⣤⣿⣿⣏⢧⠀⡇⡇⡇⡇⠀⠀⠀⡞⡸⠀⠈⠓⣿⠘⠉⠁⡎⠀⠈⢎⢳⡿⠁\n"
                "⠀⠀⠀⠀⠀⡠⢣⡎⠀⣀⡀⣇⢀⣴⠀⢇⣹⢳⢹⣿⠟⠛⣌⢆⡇⣇⡇⠇⠀⢀⠀⠱⣹⣄⣀⣴⣿⢀⠀⣀⣧⠀⠀⢸⢸⡁⠀\n"
                "⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠉⠀⠈⠁⠀⠉⠉⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠀⠀⠈⠉⠉⠁⠈⠉⠀⠈⠉⠀⠀⠀⠉⠀⠀\n"
                "Welcome to the CSAI Study Plan Editor! Enter 'start'.     \n ";

    printSlowly(Zewail_logo);

    std::string command;

    while (true) {
        std::cout << "-> ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        } else if (command == "start") {
            studentinput.setDetails(studentJSON());
        } else if (command == "student") {
            std::string major = studentinput.getMajor();
            std::string concentration = studentinput.getConcentration();
            std::string year = studentinput.getyear();
            std::string cGPA = studentinput.getcGPA();
            bool overload = studentinput.getcanOverload();
        }
    }
}
