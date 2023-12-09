#include "actionPush.hpp"

void ActionPush::enemyAction(){
    if (std::abs(enemyCoords.getX() - contr.getCoords()->getX()) <= 1 || std::abs(enemyCoords.getY() - contr.getCoords()->getY()) <= 1){
        contr.getCoords()->setX(1);
        contr.getCoords()->setY(1);
    }
}