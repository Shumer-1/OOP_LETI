#include "game.h"


Game::Game(Controller& controller, Player& player, Field& field): controller(controller), player(player), field(field){
    game_state = GameState::NotStarted;
}
void Game::startGame(){
    game_state = GameState::Playing;
    std::cout << "Game is started\n";
    isPlaying();
}

void Game::endGame(){
    game_state = GameState::Completed;
    std::cout << "Game is completed\n";
}

void Game::isPlaying(){
    Show::showField(field, controller);

    FileRead fr = FileRead();
    InputAction ia = InputAction(fr.getControlKeys());
    while (true){
        Commands cmd = ia.readAction();
        if (cmd == Command_EndGame){
            Show::showField(field, controller);
            std::cout << player.getHp()<< " HP\n"; 
            break;
        }
        if (cmd == Command_Empty){
            Show::showField(field, controller);
            std::cout << player.getHp() << " HP\n";
        }
        else{
            Move move;
            if (cmd == Command_Up){
                move = Down;
            }
            if (cmd == Command_Down){
                move = Up;
            }
            if (cmd == Command_Left){
                move = Left;
            }
            if (cmd == Command_Right){
                move = Right;
            }
            controller.movePlayer(move, 1);
            Show::showField(field, controller);
            std::cout << player.getHp() << " HP\n";
        }
    }
    endGame();
}