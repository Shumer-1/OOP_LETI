#include "trap.h"

void TrapEvent::action(Controller& controller){
    int health = controller.getPlayersParametrs(ParPlayer::HP) - DAMAGE_TRAP;
    if (health <= 0){
        // game over!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    else{
        controller.changePlayersParametrs(ParPlayer::HP, -DAMAGE_TRAP);
    }
}