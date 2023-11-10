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
    public:
    Field static generateLevel(Controller& contr);
    bool static checkPassability(Field& field, int x, int y);
    //void static showField(Field& field);
};
#endif