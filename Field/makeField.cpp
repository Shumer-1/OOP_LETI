#include "makeField.h"
#include "../Events/heal.h"
#include "../Events/trap.h"
#include "../Events/teleport.h"
#include "../Controller/controller.h"

void MakeField::makeWall(Coords& first, Coords& second, Field& field){
    if (first.getX() != second.getX()){
        for (int i = first.getX(); i < second.getX(); i++){
            field.getCell(i, first.getY()).setPassability(false);
        }
    }
    if (first.getY() != second.getY()){
        for (int i = first.getY(); i < second.getY(); i++){
            field.getCell(first.getX(), i).setPassability(false);
        }
    }
    
}

void MakeField::firstLevel(Controller& contr, Field& field){
    // 10y на 20x
    Coords first = Coords(5, 5); 
    Coords second = Coords(10, 5);
    makeWall(first, second, field);
    Coords first = Coords(5, 5); 
    Coords second = Coords(5, 10);
    makeWall(first, second, field);
    Event* event = new TrapEvent(10, contr);
    field.getCell(0, 1).setEvent(event);
    field.getCell(18, 9).setEvent(event);
    Event* heal = new HealEvent(10, contr);
    field.getCell(19, 0).setEvent(event);
    Coords coords = Coords(0, 9);
    Event* tel = new TeleportEvent(contr, coords);
    field.getCell(4, 4).setEvent(event);
}

