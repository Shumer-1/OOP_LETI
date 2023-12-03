#ifndef MESSAGE
#define MESSAGE

#include <string>
#include <ostream>


class Message{
    public:
    std::string virtual getMessage() = 0;
};

#endif