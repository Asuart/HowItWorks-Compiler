#include "../headers/console.h"

void Console::Error(const std::string errorMessage) {
    std::cout << RED << "error: " << errorMessage << RESET << std::endl;
}

void Console::Log(const std::string logMessage) {
    std::cout << BOLDWHITE << "log: " << logMessage << RESET << std::endl;
}