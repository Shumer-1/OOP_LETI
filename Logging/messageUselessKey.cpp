#include "./messageUselessKey.hpp"
#include <string>

std::string MessageUselessKey::getMessage(){
    std::string res_string = "It is useless key: " + this->getUselessKey() + "\n";
}
MessageUselessKey::MessageUselessKey(std::string key): key(key){}

std::string MessageUselessKey::getUselessKey() const{
    return key;
}