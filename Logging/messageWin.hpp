#ifndef MESSAGEWIN
#define MESSAGEWIN

#include "./message.hpp"
#include "../Controller/controller.h"

class MessageWin: public Message{
    Player& player;
    public:
    MessageState getMessageState();
    MessageWin(Player& player);
    int getHP();
    int getDamage();
};
#endif