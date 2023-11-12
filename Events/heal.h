#ifndef HEAL_H
#define HEAL_H

#include "event.h"


class HealEvent: public Event{
    private:
    int heal;
    Controller& controller;

    public:
    void action();
    HealEvent(int heal, Controller& controller);
    char icon();
    HealEvent* copy();
};

#endif