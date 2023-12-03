#include "./messageControlKey.hpp"

MessageControlKey::MessageControlKey(Commands cmd, std::string key): cmd(cmd), key(key){}
Commands MessageControlKey::getCommand() const{
    return cmd;
} 
std::string MessageControlKey::getKey() const{
    return key;
}
std::string MessageControlKey::getMessage(){
    std::string cmd_str = "";
    if (cmd == Command_Down){
        cmd_str = "DOWN";
    }
    if (cmd == Command_EndGame){
        cmd_str = "END";
    }
    if (cmd == Command_Up){
        cmd_str = "UP";
    }
    if (cmd == Command_Right){
        cmd_str = "RIGHT";
    }
    if (cmd == Command_Left){
        cmd_str = "Left";
    }
    std::string new_string = "You used the control key " + this->getKey() + " and it is the command " + cmd_str;
    return new_string;
}