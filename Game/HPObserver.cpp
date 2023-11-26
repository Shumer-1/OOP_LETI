#include "./HPObserver.h"

bool HPObserver::update(){
    if (contr.getPlayersParametrs(HP) != old_hp){
        old_hp = contr.getPlayersParametrs(HP);
        return true;
    }
    return false;
}
HPObserver::HPObserver(Controller &contr): contr(contr){
    old_hp = contr.getPlayersParametrs(ParPlayer::HP);
}