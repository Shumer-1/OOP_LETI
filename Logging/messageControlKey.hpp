#ifndef MESSAGECONTROLKEY
#define MESSAGECONTROLKEY

#include "./message.hpp"
#include "../InputAction/inputAction.h"

class MessageControlKey: public Message{
    Commands cmd;
    std::string key; 

    public:
    MessageControlKey(Commands cmd, std::string key);
    Commands getCommand() const;
    std::string getKey() const;
    std::string getMessage();
};
#endif