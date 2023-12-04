#ifndef FILELOGGER
#define FILELOGGER

#include <iostream>
#include "./logger.hpp"
#include "./operator.hpp"
#include <ostream>

class FileLogger: public Logger{
    public:
    void write(const Message* message);
};
#endif