#include "Characters/player.h"

#include "Controller/controller.h"

#include "Field/field.h"

#include "Field/cell.h"


int main(){ 
    // как сделать гейм овер лучше
    // норм ли все с иментами или надо по-другому
    // Makefile - как его лучше переделать
    // норм ли то, что разбил на папки
    Player player = Player();
    Field field = Field(5, 5);
    int * coords = new int[2];
    coords[0] = 1;
    coords[1] = 1; 

    Controller* controller = new Controller(player,coords, field);
    delete [] coords;
    Move move = Up;

    Field new_field = Field(field);
    std::cout << new_field.getStartCoords().getX() << std::endl;
    new_field.getCell(0,0).setPassability(false);

    std::cout << new_field.getCell(0, 0).getPassability() << std::endl;
    std::cout << controller->getCoords()->getY() << '\n';
    controller->movePlayer(move, 2);
    std::cout << controller->getCoords()->getY();
    int a = 10;
    int * b;
    b = &a;
    std::cout << *b;
    //int *b;
    //*b = *a;
    //std::cout << "!!!!!!!!!!!!!!!!!" << *b;

    return 0;
    //sfml - для графики.
}