#include "./messageUselessKey.hpp"
#include <string>

MessageState MessageUselessKey::getMessageState(){
    return MessageState::MessageUselessKeyState;
}
MessageUselessKey::MessageUselessKey(std::string key): key(key){}

std::string MessageUselessKey::getUselessKey(){
    return key;
}