#include "./messageWin.hpp"

MessageState MessageWin::getMessageState(){
    return MessageState::MessageWinState;
}

MessageWin::MessageWin(Player& player):player(player){}

int MessageWin::getDamage(){
    return player.getDamage();
}
int MessageWin::getHP(){
    return player.getHp();
}