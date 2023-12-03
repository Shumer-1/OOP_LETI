#include "./messageGame.hpp"

MessageGame::MessageGame(Field& field, Controller& contr): contr(contr), field(field){}
Coords MessageGame::getStartCoords(){
    Coords coords = Coords();
    return coords;
}
int MessageGame::getSizeX() const{
    return field.getSizeX();
}
int MessageGame::getSizeY() const{
    return field.getSizeY();
}
std::string MessageGame::getMessage(){
    std::string res_string1 = "You started new game. Weight of field is " + std::to_string(this->getSizeX()) + " and height is " + std::to_string(this->getSizeY()) + "\n";
    return res_string1;
}