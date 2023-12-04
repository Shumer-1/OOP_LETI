#ifndef CONSOLELOGGER
#define CONSOLELOGGER
#include "./logger.hpp"

class ConsoleLogger: public Logger{

    public:
    void write(const Message* message);
    ConsoleLogger() = default;
};
#endif