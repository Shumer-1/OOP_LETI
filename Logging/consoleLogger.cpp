#include "./consoleLogger.hpp"

void ConsoleLogger::write(Message* message){
    std::string str = message->getMessage();
    std::cout << str; 
}