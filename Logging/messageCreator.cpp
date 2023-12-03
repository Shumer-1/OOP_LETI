#include "./messageCreator.hpp"

void MessageCreator::writeMessage(Message* message){
    if (message == nullptr) return;

    MessageWin* mesWin = dynamic_cast<MessageWin*>(message);
    if (mesWin != nullptr){
        // <<
    }
    MessageLose* mesLose = dynamic_cast<MessageLose*>(message);
    if (mesWin != nullptr){
        // <<
    }
    MessageGame* mesGame = dynamic_cast<MessageGame*>(message);
    if (mesWin != nullptr){
        // <<
    }
    MessageControlKey* mesControl = dynamic_cast<MessageControlKey*>(message);
    if (mesWin != nullptr){
        // <<
    }
    MessageUselessKey* mesUseless = dynamic_cast<MessageUselessKey*>(message);
    if (mesWin != nullptr){
        // <<
    }
}