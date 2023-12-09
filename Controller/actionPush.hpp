#include "./action.hpp"
#include "controller.h"

class ActionPush: public Action{
    Controller& contr;
    Coords& enemyCoords;
    public:
    void enemyAction();
};
