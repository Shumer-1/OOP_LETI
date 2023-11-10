#ifndef INPUTACTION_H
#define INPUTACTION_H

#include <string>
#include <map>
#include "./readFileCommand.h"

class InputAction{
    bool state;
    std::map<std::string, Commands> cmds;

    public:
    InputAction(std::map<std::string, Commands> map);
    Commands readAction();
};
#endif