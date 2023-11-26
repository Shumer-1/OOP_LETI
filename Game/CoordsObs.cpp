#include "./CoordsObs.hpp"

bool CoordsObs::update(){
    if (coords.getX() != contr.getCoords()->getX() || coords.getY() != contr.getCoords()->getY()){
        coords.setX(contr.getCoords()->getX());
        coords.setY(contr.getCoords()->getY());
        return true;
    }
    return false;
}

CoordsObs::CoordsObs(Controller& contr): contr(contr){
    coords.setX(contr.getCoords()->getX());
    coords.setY(contr.getCoords()->getY());
}