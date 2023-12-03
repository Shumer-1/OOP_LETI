#include "./handler.hpp"

Handler::Handler(ConsoleLogger& consL, FileLogger& fileL, int mode): consL(consL), fileL(fileL), mode(mode){}
void Handler::logInfo(Message* message){
    if (mode == 1){
        consL.write(message);
    }
    if (mode == 2){
        fileL.write(message);
    }
    if (mode == 3){
        consL.write(message);
        fileL.write(message);
    }
}