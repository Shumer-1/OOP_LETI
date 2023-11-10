#include "readFileCommand.h"
#include <iostream>

FileRead::FileRead(){
    std::string line_UP;
    std::string line_DOWN;
    std::string line_RIGHT;
    std::string line_LEFT;
    std::string line_ENDGAME;
    std::ifstream in("commands.txt");
    if (in.is_open()){
        if (!(std::getline(in, line_UP) && std::getline(in, line_DOWN) && std::getline(in, line_RIGHT) && std::getline(in, line_LEFT) && std::getline(in, line_ENDGAME))){
            setDefault();
        }
        else{
            // std::cout << line_UP << '\n';
            // std::cout << line_RIGHT << '\n';
            // std::cout << line_LEFT << '\n';
            // std::cout << line_DOWN << '\n';
            // std::cout << line_ENDGAME << '\n';
            control_keys[line_UP] = Commands::Command_Up;
            control_keys[line_DOWN] = Commands::Command_Down;
            control_keys[line_LEFT] = Commands::Command_Left;
            control_keys[line_RIGHT] = Commands::Command_Right;
            control_keys[line_ENDGAME] = Commands::Command_EndGame;
        }
    }
    in.close();
}

void FileRead::setDefault(){
    control_keys["w"] = Commands::Command_Up;
    control_keys["s"] = Commands::Command_Down;
    control_keys["a"] = Commands::Command_Left;
    control_keys["d"] = Commands::Command_Right;
    control_keys["p"] = Commands::Command_EndGame;
}

std::map<std::string, Commands> FileRead::getControlKeys(){
    return control_keys;
}