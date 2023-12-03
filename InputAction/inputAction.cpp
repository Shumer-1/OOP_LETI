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

    if (cmds.count(c) == 1){
        Commands cmd = cmds[c];
        now_str = c;
        return cmd;
    }
    //system("stty cooked");
    return Command_Empty;
}
std::string InputAction::getKey(){
    return now_str;
}