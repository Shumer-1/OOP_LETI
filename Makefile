f_all: all clean
all: main.o player.o field.o controller.o  cell.o coords.o heal.o teleport.o trap.o makeField.o showField.o readFileCommand.o inputAction.o game.o gameTracker.o CoordsObs.o HPObserver.o messageWin.o messageControlKey.o messageGame.o messageLose.o messageUselessKey.o consoleLogger.o fileLogger.o  handler.o
	g++ main.o player.o field.o controller.o cell.o coords.o heal.o trap.o teleport.o makeField.o showField.o readFileCommand.o inputAction.o gameTracker.o CoordsObs.o HPObserver.o game.o messageWin.o messageControlKey.o messageGame.o messageLose.o messageUselessKey.o consoleLogger.o fileLogger.o  handler.o -o main
main.o: main.cpp Characters/player.h Controller/controller.h Field/field.h Field/cell.h Field/coords.h Events/event.h Events/heal.h Events/teleport.h Events/trap.h Game/game.h
	g++ -c main.cpp
game.o: Characters/player.h Field/field.h Controller/controller.h Field/cell.h Field/coords.h Events/heal.h Events/teleport.h Events/trap.h Field/makeField.h Field/showField.h InputAction/readFileCommand.h InputAction/inputAction.h Game/game.h Game/game.cpp Game/CoordsObs.hpp Game/HPObserver.h Game/gameTracker.hpp Game/Observer.hpp Logging/message.hpp Logging/messageControlKey.hpp Logging/messageGame.hpp Logging/messageLose.hpp Logging/messageUselessKey.hpp Logging/messageWin.hpp Logging/handler.hpp Logging/consoleLogger.hpp Logging/fileLogger.hpp
	g++ -c Game/game.cpp
player.o: Characters/player.cpp Characters/player.h
	g++ -c Characters/player.cpp
field.o: Field/field.cpp Field/field.h Field/cell.h Field/coords.h Events/event.h Controller/controller.h
	g++ -c Field/field.cpp
controller.o: Controller/controller.cpp Controller/controller.h Characters/player.h Field/field.h Field/cell.h Field/coords.h Events/event.h
	g++ -c Controller/controller.cpp
cell.o: Field/cell.cpp Field/cell.h Field/coords.h Events/event.h Events/heal.h Events/teleport.h Events/trap.h
	g++ -c Field/cell.cpp
coords.o: Field/coords.cpp Field/coords.h Field/field.h
	g++ -c Field/coords.cpp
heal.o: Events/event.h Controller/controller.h Events/heal.cpp Events/heal.h
	g++ -c Events/heal.cpp
trap.o: Events/event.h Controller/controller.h Events/trap.h Events/trap.cpp
	g++ -c Events/trap.cpp
teleport.o: Events/event.h Controller/controller.h Events/teleport.h Events/teleport.cpp
	g++ -c Events/teleport.cpp
makeField.o: Controller/controller.h Field/field.h Field/makeField.cpp Field/makeField.h
	g++ -c Field/makeField.cpp
showField.o: Field/showField.cpp Field/showField.h Field/field.h Events/trap.h Events/heal.h Events/teleport.h Events/event.h
	g++ -c Field/showField.cpp
readFileCommand.o: InputAction/readFileCommand.cpp InputAction/readFileCommand.h
	g++ -c InputAction/readFileCommand.cpp
inputAction.o: InputAction/inputAction.cpp InputAction/inputAction.h InputAction/readFileCommand.h
	g++ -c InputAction/inputAction.cpp
CoordsObs.o: Controller/controller.h Game/Observer.hpp Game/CoordsObs.hpp Game/CoordsObs.cpp
	g++ -c Game/CoordsObs.cpp
HPObserver.o: Controller/controller.h Game/Observer.hpp Game/HPObserver.h Game/HPObserver.cpp
	g++ -c Game/HPObserver.cpp
gameTracker.o: Field/showField.h Game/HPObserver.h Game/CoordsObs.hpp Game/gameTracker.hpp Game/gameTracker.cpp
	g++ -c Game/gameTracker.cpp
messageControlKey.o: Logging/messageControlKey.hpp Logging/messageControlKey.cpp Logging/message.hpp InputAction/inputAction.h 
	g++ -c Logging/messageControlKey.cpp
messageGame.o: Logging/messageGame.hpp Logging/messageGame.cpp Logging/message.hpp Controller/controller.h Field/field.h
	g++ -c Logging/messageGame.cpp
messageLose.o: Logging/messageLose.hpp Logging/messageLose.cpp Logging/message.hpp Controller/controller.h
	g++ -c Logging/messageLose.cpp
messageUselessKey.o: Logging/messageUselessKey.cpp Logging/messageUselessKey.hpp Logging/message.hpp InputAction/inputAction.h
	g++ -c Logging/messageUselessKey.cpp
messageWin.o: Logging/messageWin.cpp Logging/messageWin.hpp Logging/message.hpp Controller/controller.h
	g++ -c Logging/messageWin.cpp
consoleLogger.o: Logging/consoleLogger.hpp Logging/consoleLogger.cpp Logging/message.hpp Logging/logger.hpp
	g++ -c Logging/consoleLogger.cpp
fileLogger.o: Logging/fileLogger.hpp Logging/fileLogger.cpp Logging/logger.hpp Logging/operator.hpp
	g++ -c Logging/fileLogger.cpp
handler.o: Logging/handler.hpp Logging/handler.cpp Logging/consoleLogger.hpp Logging/fileLogger.hpp
	g++ -c Logging/handler.cpp
operator.o: Logging/message.hpp Logging/messageControlKey.hpp Logging/messageGame.hpp Logging/messageLose.hpp Logging/messageUselessKey.hpp Logging/messageWin.hpp Logging/operator.cpp Logging/operator.hpp
	g++ -c Logging/operator.cpp
clean:
	rm -rf *.o
