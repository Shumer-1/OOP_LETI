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
#include "Controller/action.hpp"
#include "Controller/actionDamage.hpp"
#include "Controller/actionPush.hpp"
#include "Controller/enemyController.hpp"
#include "Controller/movement.hpp"
#include "Controller/movementGivenWay.hpp"
#include "Controller/movementToPlayer.hpp"

#include <vector>
class EnemyController;
int main(){
    //Enemy<MovementGivenWay, Action> enemy = Enemy<MovementGivenWay, Action>();
    std::cout << "Select mode of logging: ConsoleLogger, FileLogger or both\n";
    std::cout << "ConsoleLogger? Yes or no\n";
    std::string console_mode;
    std::cin >> console_mode;
    std::cout << "FileLogger? Yes or no\n";
    std::string file_mode;
    std::cin >> console_mode;
    bool consL = false;
    bool fileL = false;
    if (console_mode == "Yes"){
        consL = true;
    }
    if (file_mode == "Yes"){
        fileL = true;
    }
    bool *lgs = new bool[2];
    Player player = Player();
    Field field = Field();
    Controller contr = Controller(player, field);
    Enemy<MovementGivenWay, ActionDamage> firstEnemy = Enemy<MovementGivenWay, ActionDamage>(contr, field);
    Enemy<MovementToPlayer, ActionPush> secondEnemy = Enemy<MovementToPlayer, ActionPush>(contr, field);
    EnemyController enContr = EnemyController(firstEnemy, secondEnemy);
    //Show::showField(field, contr);
    field = MakeField::generateLevel(contr);
    Game game = Game(contr, player, field, lgs, enContr);
    delete[] lgs;
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