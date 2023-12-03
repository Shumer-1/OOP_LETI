#ifndef OPERATOR
#define OPERATOR
#include "./message.hpp"
#include "./messageControlKey.hpp"
#include "./messageGame.hpp"
#include "./messageLose.hpp"
#include "./messageUselessKey.hpp"
#include "./messageWin.hpp"
#include <ostream>


std::ostream& operator<<(std::ostream& stream, const Message* mes);

#endif