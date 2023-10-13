#include "heal.h"

void HealEvent::action(Controller& controller){
    controller.changePlayersParametrs(ParPlayer::HP, HP_DEFAULT - controller.getPlayersParametrs(ParPlayer::HP));
}