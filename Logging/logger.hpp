#ifndef LOGGER
#define LOGGER
#include "./message.hpp"
#include <iostream>
class Logger{
    public:
    void virtual write(const Message* message) = 0;
};

#endif