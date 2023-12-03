#ifndef MESSAGEWIN
#define MESSAGEWIN

#include "./message.hpp"
#include "../Controller/controller.h"

class MessageWin: public Message{
    Player& player;
    public:
    std::string getMessage();
    MessageWin(Player& player);
    int getHP() const;
    int getDamage() const;
};
#endif