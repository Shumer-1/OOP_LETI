#ifndef HEAL_H
#define HEAL_H

#include "event.h"

class HealEvent: public Event{
    public:
    void action(Controller& controller);
};

#endif