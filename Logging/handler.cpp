#include "./handler.hpp"
// set для логгеров, список инициализации - передача множества - создаем только то, что нужно.
Handler::Handler(std::vector<Logger*> loggers): loggers(loggers){}
void Handler::logInfo(Message* message){
    for (auto &logger: loggers){
        logger->write(message);
    }
}