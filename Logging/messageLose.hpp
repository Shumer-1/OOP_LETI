#ifndef MESSAGELOSE
#define MESSAGELOSE
#include "./message.hpp"
#include "../Controller/controller.h"

class MessageLose: public Message{
    Controller& contr;

    public:
    MessageLose(Controller& contr);
    MessageState getMessageState();
    Coords* getCoords();
};
#endif MESSAGELOSE