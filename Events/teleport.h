#ifndef TELEPORT_H
#define TELEPORT_H

#include "event.h"

class TeleportEvent: public Event{
    void action(Controller& controller, Coords& coords);
};


#endif