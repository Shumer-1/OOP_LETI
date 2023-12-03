#include "./message.hpp"
#include <iostream>
class Logger{
    public:
    void virtual write(Message* message) = 0;
};