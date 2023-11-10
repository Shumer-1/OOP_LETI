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
#include <iostream>

enum GameState{
    Playing,
    Completed,
    NotStarted
};
class Show;
class MakeField;

class Game{
    private:
    Controller& controller;
    Player& player;
    Field& field;
    GameState game_state;
    
    void isPlaying();
    public:
    Game(Controller& controller, Player& player, Field& field);
    void startGame();
    void endGame();
};
#endif