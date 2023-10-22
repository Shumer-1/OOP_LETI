#include "trap.h"

void TrapEvent::action(){
    int health = controller.getPlayersParametrs(ParPlayer::HP) - damage;
    if (health <= 0){
        controller.setGameOver(true);
    }
    else{
        controller.changePlayersParametrs(ParPlayer::HP, -damage);
    }
}

TrapEvent::TrapEvent(int damage, Controller& controller): controller(controller), damage(damage){}