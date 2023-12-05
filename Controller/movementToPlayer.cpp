#include "./movementToPlayer.hpp"

MovementToPlayer::MovementToPlayer(Coords& coords, Controller& contr, Field& field): coords(coords), contr(contr), field(field){}

Coords MovementToPlayer::getCoords(){
    return coords;
}

void MovementToPlayer::move(){
    if (std::abs(contr.getCoords()->getX() - coords.getX()) == 1 || std::abs(contr.getCoords()->getY() - coords.getY()) == 1){
        return;
    }
    if (contr.getCoords()->getY() > coords.getY()){
        coords.setY(coords.getY()+1);
        field.getCell(coords.getX(), coords.getY()).setPassability(true);
    }
    else if (contr.getCoords()->getY() < coords.getY()){
        coords.setY(coords.getY()-1);
        field.getCell(coords.getX(), coords.getY()).setPassability(true);
    }
    else if (contr.getCoords()->getX() > coords.getX()){
        coords.setX(coords.getX()+1);
        field.getCell(coords.getX(), coords.getY()).setPassability(true);
    }
    else if (contr.getCoords()->getY() < coords.getY()){
        coords.setY(coords.getY()-1);
        field.getCell(coords.getX(), coords.getY()).setPassability(true);
    }
}