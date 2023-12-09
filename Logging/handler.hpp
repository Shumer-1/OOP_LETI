#ifndef HANDLER
#define HANDLER


#include "./consoleLogger.hpp"
#include "./fileLogger.hpp"
#include <vector>

class Handler{
    std::vector<Logger> loggers;
    
    int mode;

    public:
    Handler(std::vector<Logger> loggers);
    void logInfo(Message* message);

};
#endif