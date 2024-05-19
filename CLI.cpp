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

void CLI::searchCourse(const std::string& courseCodePrefix) {
    std::vector<std::string> results = Course::searchCourse(courseCodePrefix);
    for (const auto& course : results) {
        std::cout << course << std::endl;
    }
}

void CLI::handleCommand(const std::string& command) {
    if (command == "add_semester") {
        std::string name, type;
        std::cout << "Enter semester name: ";
        std::getline(std::cin, name); // Use getline to avoid issues with cin
        std::cout << "Enter semester type (Fall/Spring/Summer): ";
        std::getline(std::cin, type); // Use getline to avoid issues with cin

        studyPlan.addSemester(name, type);
    } else if (command == "add_course") {
        std::string semesterName, courseCode;
        std::cout << "Enter semester name: ";
        std::getline(std::cin, semesterName); // Use getline to avoid issues with cin
        std::cout << "Enter course code: ";
        std::getline(std::cin, courseCode); // Use getline to avoid issues with cin
        studyPlan.addCourseToSemester(semesterName, courseCode);
    } else if (command == "start") {
        studentinput.setDetails(studentJSON());
    } else if (command == "student") {
        std::string major = studentinput.getMajor();
        std::string concentration = studentinput.getConcentration();
        std::string year = studentinput.getyear();
        std::string cGPA = studentinput.getcGPA();
        bool overload = studentinput.getcanOverload();
    }
      else if (command.substr(0, 6) == "search") {
        std::string courseCodePrefix = command.substr(7);
        searchCourse(courseCodePrefix);
    } else {
        std::cout << "Unknown command.\n";
    }
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
        } else {
            handleCommand(command);
        }
    }
}
