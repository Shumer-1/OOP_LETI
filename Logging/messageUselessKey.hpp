#ifndef MESSAGEUSELESSKEY
#define MESSAGEUSELESSKEY

#include "./message.hpp"
#include "../InputAction/inputAction.h"

class MessageUselessKey: public Message{
    std::string key;

    public:
    std::string getMessage();
    MessageUselessKey(std::string key);
    std::string getUselessKey() const;
};

#endif