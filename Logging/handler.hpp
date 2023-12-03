#include "./consoleLogger.hpp"
#include "./fileLogger.hpp"

class Handler{
    ConsoleLogger& consL;
    FileLogger& fileL;
    int mode;

    public:
    Handler(ConsoleLogger& consL, FileLogger& fileL, int mode);
    void logInfo(Message* message);

};