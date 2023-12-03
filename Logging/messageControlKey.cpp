#include "./messageControlKey.hpp"

MessageControlKey::MessageControlKey(Commands cmd, std::string key): cmd(cmd), key(key){}
Commands MessageControlKey::getCommand(){
    return cmd;
}
std::string MessageControlKey::getKey(){
    return key;
}
MessageState MessageControlKey::getMessageState(){
    return MessageState::MessageControlKeyState;
}