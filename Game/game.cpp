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
    HPObserver hp_obs = HPObserver(controller);
    CoordsObs coords_obs = CoordsObs(controller);
    GameTracker game_tracker = GameTracker(hp_obs, coords_obs, controller, field);

    while (true){
        game_tracker.gameTracking();
        Commands cmd = ia.readAction();
        if (cmd == Command_EndGame){
            break;
        }
        if (cmd != Command_Empty && cmd != Command_EndGame){
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
            if (controller.getCoords()->getX() == DEFAULT_SIZE_X-1 && controller.getCoords()->getY() == DEFAULT_SIZE_Y-1){
                std::cout << "VICTORY!\n";
                break;
            }
            if (player.getHp() == 0){
                std::cout << "You DIED!\n";
                break;
            }
        }
    }
    endGame();
}