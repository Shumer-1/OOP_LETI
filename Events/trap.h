#ifndef TRAP_H
#define TRAP_H

#define DAMAGE_TRAP 10
#include "event.h"

class TrapEvent: public Event{
    private:
    int damage;
    Controller& controller;
    public:
    void action();
    TrapEvent(int damage, Controller& controller);
    TrapEvent* copy();
    char icon();
};

#endif