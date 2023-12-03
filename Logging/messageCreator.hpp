#ifndef MESSAGECREATOR
#define MESSAGECREATOR

#include "./message.hpp"
#include "./messageControlKey.hpp"
#include "./messageGame.hpp"
#include "./messageLose.hpp"
#include "./messageWin.hpp"
#include "./messageUselessKey.hpp"
#include "../Controller/controller.h"
#include "../InputAction/inputAction.h"
#include "../InputAction/readFileCommand.h"

class MessageCreator{
    public:
    void writeMessage(Message* message);

};
#endif