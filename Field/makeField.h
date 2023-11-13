#ifndef MAKEFIELD_H
#define MAKEFIELD_H
#include "../Controller/controller.h"
#include <random>
#include <iostream>
#include "field.h"
class Controller;
class Field;

class MakeField{
    // статик класс, в котором есть только заполнение поля
    bool static deadend(int x, int y, Field& field);
    public:
    void static mazemake(Field& field);
    Field static generateLevel(Controller& contr);
    Field static generateNew(Controller& contr);
    bool static checkPassability(Field& field, int x, int y);
    //void static showField(Field& field);
};

#endif