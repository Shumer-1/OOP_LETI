#ifndef TRAP_H
#define TRAP_H

#define DAMAGE_TRAP 10
#include "event.h"

class TrapEvent: public Event{
    public:
    void action(Controller& controller);
};

#endif