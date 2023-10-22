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
    for (int i = 0; i < field.getSizeY(); i++){
        for (int j = 0; j < field.getSizeY(); j++){
            field.getCell(j,i);
        }
    }
    Coords first = Coords(5, 5); 
    Coords second = Coords(10, 5);
    makeWall(first, second, field);
    first = Coords(5, 5); 
    second = Coords(5, 10);
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



void MakeField::generateLevel(Controller& contr, Field& field){
    while (true){
        std::random_device rand_wall;
        std::random_device rand_event;

        field = Field();

        HealEvent *heal = new HealEvent(10, contr);
        TrapEvent *trap = new TrapEvent(10, contr);
        Coords coords = Coords(field.getSizeX()-1, field.getSizeY()-1);
        TeleportEvent *tel = new TeleportEvent(contr, coords);
        field.getCell(rand_event() % DEFAULT_SIZE_X, rand_event() % DEFAULT_SIZE_Y).setEvent(tel);
        long rand = rand_event();
        if (field.getCell(rand % DEFAULT_SIZE_X, rand % DEFAULT_SIZE_Y).getEvent() == nullptr){
            field.getCell(rand % DEFAULT_SIZE_X, rand % DEFAULT_SIZE_Y).setEvent(tel);
            
        }
        rand = rand_event();
        if (field.getCell(rand % DEFAULT_SIZE_X, rand % DEFAULT_SIZE_Y).getEvent() == nullptr){
            field.getCell(rand % DEFAULT_SIZE_X, rand % DEFAULT_SIZE_Y).setEvent(heal);
        }
        rand = rand_event();
        if (field.getCell(rand % DEFAULT_SIZE_X, rand % DEFAULT_SIZE_Y).getEvent() == nullptr){
            field.getCell(rand % DEFAULT_SIZE_X, rand % DEFAULT_SIZE_Y).setEvent(trap);
        }

        for (int i = 0; i < field.getSizeY(); i++){
            for (int j = 0; j < field.getSizeX(); j++){
                rand = rand_wall();
                if (rand % 3 == 0 && field.getCell(j, i).getEvent() == nullptr){
                    field.getCell(j, i).setPassability(false);
                }
            }
        }
        if (checkPassability(field, field.getStartCoords().getX(), field.getStartCoords().getY())){
            break;
        }
        else{
            delete heal;
            delete trap;
            delete tel;
        }
    }
}

bool MakeField::checkPassability(Field& field, int x, int y){
    if (field.getCell(field.getFinalCoords().getX(), field.getFinalCoords().getY()).getPassability() == false){
        return false;
    }
    if (field.getCell(x, y).getPassability() == false){
        return false;
    }
    if (x == field.getSizeX()-1 && y == field.getSizeY()-1)
        return true;
    return checkPassability(field, x+1, y) + checkPassability(field, x, y + 1);
}


void MakeField::showField(Field& field){
    for (int i = 0; i < field.getSizeY(); i++){
        for (int j = 0; j < field.getSizeX(); j++){
            if (field.getCell(j, i).getPassability()){
                std::cout << '.';
            }
            else {std::cout << '|';}
        }
        std::cout << '\n';
    }
}