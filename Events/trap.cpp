#include "trap.h"

void TrapEvent::action(){
    controller.changePlayersParametrs(ParPlayer::HP, -damage);
}

TrapEvent::TrapEvent(int damage, Controller& controller): controller(controller), damage(damage){}

TrapEvent* TrapEvent::copy(){
    return new TrapEvent(*this);
}
char TrapEvent::icon(){
    return 'W';
}