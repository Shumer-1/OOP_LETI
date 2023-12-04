#include "./inputAction.h"
#include <iostream>


InputAction::InputAction(std::map<std::string, Commands> map):cmds(map){}
Commands InputAction::readAction(){

    //std::string cmd;
    char c[1];
    system("stty raw");
    c[0] = getchar();
    system("stty cooked");
    // std::string temp = c;
    //system("clear");
    Commands cmd = cmds[c];
    if (cmds.count(c) == 1){
        now_str = c;
        return cmd;
    }
    now_str = c;
    //system("stty cooked");
    return Command_Empty;
}
std::string InputAction::getKey(){
    return now_str;
}