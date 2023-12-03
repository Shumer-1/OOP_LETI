#ifndef GAME_H
#define GAME_H

#include "../Characters/player.h"
#include "../Controller/controller.h"
#include "../Field/field.h"
#include "../Field/cell.h"
#include "../Events/trap.h"
#include "../Events/heal.h"
#include "../Field/makeField.h"
#include "../Field/showField.h"
#include "../InputAction/inputAction.h"
#include "../InputAction/readFileCommand.h"
#include "./Observer.hpp"
#include "./HPObserver.h"
#include "./CoordsObs.hpp"
#include "./gameTracker.hpp"
#include "../Logging/message.hpp"
#include "../Logging/messageControlKey.hpp"
#include "../Logging/messageGame.hpp"
#include "../Logging/messageLose.hpp"
#include "..//Logging/messageUselessKey.hpp"
#include "../Logging/messageWin.hpp"
#include "../Logging/handler.hpp"
#include "../Logging/consoleLogger.hpp"
#include "../Logging/fileLogger.hpp"

#include <iostream>

enum GameState{
    Playing,
    Completed,
    NotStarted
};
class Show;
class MakeField;
class GameTracker;

class Game{
    private:
    Controller& controller;
    Player& player;
    Field& field;
    GameState game_state;
    int mode;
    
    void isPlaying();
    public:
    Game(Controller& controller, Player& player, Field& field, int mode);
    void startGame();
    void endGame();
};
#endif