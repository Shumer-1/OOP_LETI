#include "./action.hpp"
#include "controller.h"

class ActionDamage: public Action{
    Controller& contr;
    Coords& enemyCoords;
    public:
    void enemyAction();
};
