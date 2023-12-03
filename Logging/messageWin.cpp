#include "./messageWin.hpp"

std::string MessageWin::getMessage(){
    std::string res_string = "You won this game. Player`s parametrs: hp " + std::to_string(this->getHP()) + " damage: " + std::to_string(this->getDamage()) + "\n"; 
}

MessageWin::MessageWin(Player& player):player(player){}

int MessageWin::getDamage() const{
    return player.getDamage();
}
int MessageWin::getHP() const{
    return player.getHp();
}