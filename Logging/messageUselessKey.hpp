#ifndef MESSAGEUSELESSKEY
#define MESSAGEUSELESSKEY

#include "./message.hpp"
#include "../InputAction/inputAction.h"

class MessageUselessKey: public Message{
    std::string key;

    public:
    MessageState getMessageState();
    MessageUselessKey(std::string key);
    std::string getUselessKey();
};

#endif