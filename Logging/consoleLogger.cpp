#include "./consoleLogger.hpp"

void ConsoleLogger::write(const Message* message){
    std::cout << message; 
}