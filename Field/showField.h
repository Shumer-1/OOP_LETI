#ifndef SHOWFIELD_H
#define SHOWFIELD_H

#include "field.h"
#include "../Controller/controller.h"
class Controller;
class Show{
    public:
    void static showField(Field& field, Controller& contr);
};
#endif