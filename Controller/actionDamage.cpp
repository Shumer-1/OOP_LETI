#include "actionDamage.hpp"

void ActionDamage::enemyAction(){
    if (std::abs(enemyCoords.getX() - contr.getCoords()->getX()) <= 1 || std::abs(enemyCoords.getY() - contr.getCoords()->getY()) <= 1){
        contr.changePlayersParametrs(HP, -10);
    }
}