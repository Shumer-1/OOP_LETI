#include "./logger.hpp"

class ConsoleLogger: public Logger{

    public:
    void write(Message* message);
    ConsoleLogger() = default;
};