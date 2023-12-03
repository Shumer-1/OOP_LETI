#include "Characters/player.h"
#include "Controller/controller.h"
#include "Field/field.h"
#include "Field/cell.h"
#include "Events/trap.h"
#include "Events/heal.h"
#include "Field/makeField.h"
#include "Field/showField.h"
#include "InputAction/readFileCommand.h"
#include "InputAction/inputAction.h"
#include "Game/game.h"
#include <vector>


int main(){
    std::cout << "Select mode of logging: 1, 2 or 3";
    int mode;
    std::cin >> mode;
    Player player = Player();
    Field field = Field();
    Controller contr = Controller(player, field);
   
    //Show::showField(field, contr);
    field = MakeField::generateLevel(contr);
    Game game = Game(contr, player, field, mode);
    game.startGame();
    //game_over = 0;
    // как сделать гейм овер лучше - пока печать с ветвлением - три состояния игры.

    // Player player = Player();
    // Field field = Field();
    // int * coords = new int[2];
    // coords[0] = 1;
    // coords[1] = 1; 

    // Controller controller = Controller(player, coords, field);
    // field = MakeField::generateLevel(controller);
    // Show::showField(field);
    // delete [] coords;
    // std::cout << controller.getCoords()->getX() << '\n';
    // std::cout << controller.getCoords()->getY() << '\n';

    // field.getCell(1, 2).setEvent(new TrapEvent(10, controller));
    // controller.movePlayer(Move::Up, 10);

    
    // std::cout << controller.getCoords()->getX() << '\n';
    // std::cout << controller.getCoords()->getY() << '\n';

    // Field new_field = Field(field);
    // std::cout << new_field.getStartCoords().getX() << "!!!!!!!!!!!!!!"<< std::endl;


    // for (const auto &key: keys) {
    //     std::cout << key << std::endl;
    // }

    // new_field.getCell(0,0).setPassability(false);

    // std::cout << new_field.getCell(0, 0).getPassability() << std::endl;
    // std::cout << controller->getCoords()->getY() << '\n';
    // controller->movePlayer(move, 2);
    // std::cout << controller->getCoords()->getY();

    return 0;
    //sfml - для графики.
}