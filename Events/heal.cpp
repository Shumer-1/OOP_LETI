#include "heal.h"

void HealEvent::action(){
    controller.changePlayersParametrs(ParPlayer::HP, heal);
}
HealEvent::HealEvent(int heal, Controller& controller): heal(heal), controller(controller){}