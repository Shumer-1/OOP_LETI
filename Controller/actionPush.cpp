#include "actionPush.hpp"

void ActionPush::enemyAction(){
    if (enemyCoords.getX() - contr.getCoords()->getX() <= 1 || - enemyCoords.getX() + contr.getCoords()->getX() <= 1 || enemyCoords.getY() - contr.getCoords()->getY() <= 1 || -enemyCoords.getY() + contr.getCoords()->getY() <= 1){
        contr.getCoords()->setX(1);
        contr.getCoords()->setY(1);
    }
}
ActionPush::ActionPush(Controller& contr, Coords& coords): contr(contr), enemyCoords(coords){} 