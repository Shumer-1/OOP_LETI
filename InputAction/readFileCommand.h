#ifndef READFILECOMMAND_H
#define READFILECOMMAND_H

#include <string>
#include <map>
#include <fstream>
#define COUNT_OF_CMDS 5

enum Commands{
    Command_Up,
    Command_Down,
    Command_Right,
    Command_Left,
    Command_EndGame,
    Command_Empty
};

class FileRead{
    std::map<std::string, Commands> control_keys{};
    void setDefault();

    public:
        FileRead();
        std::map<std::string, Commands> getControlKeys();

};

#endif