#ifndef HPOBSERVER_HPP
#define HPOBSERVER_HPP

#include "../Controller/controller.h"
#include "./Observer.hpp"


class HPObserver: public IObserver{
    Controller& contr;
    int old_hp;

    public:
    bool update();
    HPObserver(Controller &contr);
};
#endif