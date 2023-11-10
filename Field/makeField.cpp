#include "makeField.h"
#include "../Events/heal.h"
#include "../Events/trap.h"
#include "../Events/teleport.h"
#include "../Controller/controller.h"
#include "field.h"

#define FREQUENCY 3

Field MakeField::generateLevel(Controller& contr){
    while (true){
        std::random_device rand_wall;
        std::random_device rand_event;

        Field field = Field();
       
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

        for (int i = 0; i < DEFAULT_SIZE_Y; i++){
            for (int j = 0; j < DEFAULT_SIZE_X; j++){
                rand = rand_wall();
                if (rand % FREQUENCY == 0 && field.getCell(j, i).getEvent() == nullptr){
                    field.getCell(j, i).setPassability(false);
                }
            }
        }
        if (checkPassability(field, field.getStartCoords().getX(), field.getStartCoords().getY())){
            return field;
            break;
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


// void MakeField::showField(Field& field){
//     for (int i = 0; i < field.getSizeY(); i++){
//         for (int j = 0; j < field.getSizeX(); j++){
//             if (field.getCell(j, i).getEvent() != nullptr){
//                 std::cout << '0';
//             }
//             else if (field.getCell(j, i).getPassability()){
//                 std::cout << '.';
//             }
//             else {std::cout << '|';}
//         }
//         std::cout << '\n';
//     }
// }