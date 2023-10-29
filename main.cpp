#include "Characters/player.h"
#include "Controller/controller.h"
#include "Field/field.h"
#include "Field/cell.h"
#include "Events/trap.h"
#include "Events/heal.h"
#include "Field/makeField.h"
#include "Field/showField.h"
#include <random>

int main(){ 
    //game_over = 0;
    // как сделать гейм овер лучше - пока печать с ветвлением - три состояния игры.

    Player player = Player();
    Field field = Field();
    int * coords = new int[2];
    coords[0] = 1;
    coords[1] = 1; 

    Controller controller = Controller(player,coords, field);
    field = MakeField::generateLevel(controller);
    Show::showField(field);
    delete [] coords;
    std::cout << controller.getCoords()->getX() << '\n';
    std::cout << controller.getCoords()->getY() << '\n';

    Event* event = new TrapEvent(10, controller);
    field.getCell(1, 2).setEvent(event);
    controller.movePlayer(Move::Up, 10);

    
    std::cout << controller.getCoords()->getX() << '\n';
    std::cout << controller.getCoords()->getY() << '\n';

    Field new_field = Field(field);
    std::cout << new_field.getStartCoords().getX() << "!!!!!!!!!!!!!!"<< std::endl;


    // new_field.getCell(0,0).setPassability(false);

    // std::cout << new_field.getCell(0, 0).getPassability() << std::endl;
    // std::cout << controller->getCoords()->getY() << '\n';
    // controller->movePlayer(move, 2);
    // std::cout << controller->getCoords()->getY();

    return 0;
    //sfml - для графики.
}