#include "teleport.h"

void TeleportEvent::action(){
    controller.setPlayersCoords(coords);

}
TeleportEvent::TeleportEvent(Controller& controller, Coords& coords):controller(controller), coords(coords){}