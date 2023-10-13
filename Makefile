f_all: all clean
all: main.o player.o controller.o field.o cell.o coords.o
	g++ main.o player.o controller.o field.o cell.o coords.o -o main
main.o: main.cpp Characters/player.h Controller/controller.h Field/field.h Field/cell.h Field/coords.h
	g++ -c main.cpp
player.o: Characters/player.cpp Characters/player.h
	g++ -c Characters/player.cpp
controller.o: Controller/controller.cpp Controller/controller.h Characters/player.h Field/field.h Field/cell.h Field/coords.h
	g++ -c Controller/controller.cpp
field.o: Field/field.cpp Field/field.h Field/cell.h Field/coords.h
	g++ -c Field/field.cpp
cell.o: Field/cell.cpp Field/cell.h Field/coords.h
	g++ -c Field/cell.cpp
coords.o: Field/coords.cpp Field/coords.h Field/field.h
	g++ -c Field/coords.cpp
clean:
	rm -rf *.o