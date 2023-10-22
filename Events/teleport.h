#ifndef TELEPORT_H
#define TELEPORT_H

#include "event.h"

class TeleportEvent: public Event{
    private:
    Controller& controller;
    Coords coords;

    void action();
    TeleportEvent(Controller& controller, Coords& coords);
};


#endif