#ifndef OBSERVER_HPP
#define OBSERVER_HPP

class IObserver {
    public:
    virtual bool update() = 0;
};

#endif