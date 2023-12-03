#include "./messageLose.hpp"

MessageLose::MessageLose(Controller& contr): contr(contr){}

Coords* MessageLose::getCoords() const{
    return contr.getCoords();
}
std::string MessageLose::getMessage(){
    std::string res_string = "You lose this game. Coordinate X is " + std::to_string(this->getCoords()->getX()) + ". Coordinate Y is " + std::to_string(this->getCoords()->getY()) + "\n";
    return res_string;
}
