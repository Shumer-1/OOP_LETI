#ifndef MESSAGEGAME
#define MESSAGEGAME
#include "./message.hpp"
#include "../Controller/controller.h"
#include "../Field/field.h"
class MessageGame: public Message{
    Field& field;
    Controller& contr;
    public:
    MessageGame(Field& field, Controller& contr);
    Coords getStartCoords();
    int getSizeX();
    int getSizeY();
    MessageState getMessageState();
};

#endif