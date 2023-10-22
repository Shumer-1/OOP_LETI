#include "../Controller/controller.h"
#include <random>
#include <iostream>

class MakeField{
    // статик класс, в котором есть только заполнение поля
    public:
    void static makeWall(Coords& first, Coords& second, Field& field);
    void static firstLevel(Controller& contr, Field& field);
    void static generateLevel(Controller& contr, Field& field);
    bool static checkPassability(Field& field, int x, int y);
    void static showField(Field& field);
};