#include "./messageGame.hpp"

MessageGame::MessageGame(Field& field, Controller& contr): contr(contr), field(field){}
Coords MessageGame::getStartCoords(){
    Coords coords = Coords();
    return coords;
}
int MessageGame::getSizeX(){
    return field.getSizeX();
}
int MessageGame::getSizeY(){
    return field.getSizeY();
}
MessageState MessageGame::getMessageState(){
    return MessageState::MessageGameState;
}