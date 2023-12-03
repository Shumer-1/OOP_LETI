#include "./messageLose.hpp"

MessageLose::MessageLose(Controller& contr): contr(contr){}

Coords* MessageLose::getCoords(){
    return contr.getCoords();
}
MessageState MessageLose::getMessageState(){
        return MessageState::MessageLoseState;
}
