#include "teleport.h"

void TeleportEvent::action(){
    controller.setPlayersCoords(coords);

}
TeleportEvent::TeleportEvent(Controller& controller, Coords& coords):controller(controller), coords(coords){}

TeleportEvent* TeleportEvent::copy(){
    return new TeleportEvent(*this);
}