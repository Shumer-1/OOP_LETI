#include "readFileCommand.h"
#include <iostream>

FileRead::FileRead(){
    std::string line_UP;
    std::string line_DOWN;
    std::string line_RIGHT;
    std::string line_LEFT;
    std::string line_ENDGAME;
    std::fstream in("commands.txt");
    if (in.is_open()){
        std::cout << line_ENDGAME;
        if (!(std::getline(in, line_UP) && std::getline(in, line_DOWN) && std::getline(in, line_RIGHT) && std::getline(in, line_LEFT) && std::getline(in, line_ENDGAME))){
            setDefault();
        }
        else{
            std::string test = line_DOWN + line_ENDGAME + line_LEFT + line_RIGHT + line_UP;
            int flag_repeat = 0;
            for (int i = 0; i < COUNT_OF_CMDS; i++){
                for (int j = i+1; j < COUNT_OF_CMDS; j++){
                    if (test[i] == test[j]){
                        std::cout << "Repeat\n";
                        flag_repeat = 1;
                    } 
                }
            }
            
            if (flag_repeat == 1){
                setDefault();
            }

            else{
                control_keys[line_UP] = Commands::Command_Up;
                control_keys[line_DOWN] = Commands::Command_Down;
                control_keys[line_LEFT] = Commands::Command_Left;
                control_keys[line_RIGHT] = Commands::Command_Right;
                control_keys[line_ENDGAME] = Commands::Command_EndGame;
            }
            
        }
    }
    else{
        setDefault();
    }

}

void FileRead::setDefault(){
    std::cout << "Set default keys\n";
    control_keys["w"] = Commands::Command_Up;
    control_keys["s"] = Commands::Command_Down;
    control_keys["a"] = Commands::Command_Left;
    control_keys["d"] = Commands::Command_Right;
    control_keys["p"] = Commands::Command_EndGame;
    //control_keys[" "] = Commands::Command_Jump;
}

std::map<std::string, Commands> FileRead::getControlKeys(){
    return control_keys;
}