#include "./fileLogger.hpp"
#include <fstream>
#include <ostream>

void FileLogger::write(Message* message){
    std::fstream in("logging.txt");
    in << message;
}