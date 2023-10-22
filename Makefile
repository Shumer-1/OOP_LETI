f_all: all clean
all: main.o player.o field.o controller.o  cell.o coords.o heal.o teleport.o trap.o
	g++ main.o player.o field.o controller.o cell.o coords.o heal.o trap.o teleport.o -o main
main.o: main.cpp Characters/player.h Controller/controller.h Field/field.h Field/cell.h Field/coords.h Events/event.h Events/heal.h Events/teleport.h Events/trap.h
	g++ -c main.cpp
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
clean:
	rm -rf *.o