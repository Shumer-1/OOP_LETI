#include "./fileLogger.hpp"
#include <fstream>
#include <ostream>
#include <iosfwd>

std::ostream& operator<<(std::ostream& stream, const Message* mes){
    const MessageGame* mesG = dynamic_cast<const MessageGame*>(mes);
    const MessageWin* mesW = dynamic_cast<const MessageWin*>(mes);
    const MessageLose* mesL = dynamic_cast<const MessageLose*>(mes);
    const MessageUselessKey* mesU = dynamic_cast<const MessageUselessKey*>(mes);
    const MessageControlKey* mesC = dynamic_cast<const MessageControlKey*>(mes);
    

    if (mesG){
        std::string res_string1 = "You started new game. Weight of field is " + std::to_string(mesG->getSizeX()) + " and height is " + std::to_string(mesG->getSizeY()) + "\n";
        stream << res_string1;
    }
    if (mesW){
        std::string res_string2 = "You won this game. Player`s parametrs: hp " + std::to_string(mesW->getHP()) + " damage: " + std::to_string(mesW->getDamage()) + "\n"; 
        stream << res_string2;
    }
    if (mesL){
        std::string res_string3 = "You lose this game. Coordinate X is " + std::to_string(mesL->getCoords()->getX()) + ". Coordinate Y is " + std::to_string(mesL->getCoords()->getY()) + "\n";
        stream << res_string3;
    }
    if (mesU){
        std::string res_string4 = "It is useless key: " + mesU->getUselessKey() + "\n";
        stream << res_string4;
    }
    if (mesC){
        std::string cmd_str = "";
        Commands cmd = mesC->getCommand();
        if (cmd == Command_Down){
            cmd_str = "DOWN";
        }
        if (cmd == Command_EndGame){
            cmd_str = "END";
        }
        if (cmd == Command_Up){
            cmd_str = "UP";
        }
        if (cmd == Command_Right){
            cmd_str = "RIGHT";
        }
        if (cmd == Command_Left){
            cmd_str = "Left";
        }
        std::string new_string = "You used the control key " + mesC->getKey() + " and it is the command " + cmd_str + "\n";
        stream << new_string;
    }
    return stream;
}

void FileLogger::write(const Message* message){
    std::fstream in("logging.txt", std::fstream::app);
    in << message;
}
