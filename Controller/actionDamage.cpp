#include "actionDamage.hpp"

void ActionDamage::enemyAction(){
    if (enemyCoords.getX() - contr.getCoords()->getX() <= 1 || - enemyCoords.getX() + contr.getCoords()->getX() <= 1 || enemyCoords.getY() - contr.getCoords()->getY() <= 1 || -enemyCoords.getY() + contr.getCoords()->getY() <= 1){
        contr.changePlayersParametrs(HP, -10);
    }
}
ActionDamage::ActionDamage(Controller& contr, Coords& coords): contr(contr), enemyCoords(coords){}