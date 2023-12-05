#include "./action.hpp"
#include "controller.h"

class ActionDamage: public Action{
    Controller& contr;
    public:
    void action();
};
