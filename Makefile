f_all: all clean
all: main.o player.o controller.o field.o cell.o coords.o
	g++ main.o player.o controller.o field.o cell.o coords.o -o main
main.o: main.cpp player.h controller.h field.h cell.h coords.h
	g++ -c main.cpp
player.o: player.cpp player.h
	g++ -c player.cpp
controller.o: controller.cpp controller.h player.h field.h cell.h coords.h
	g++ -c controller.cpp
field.o: field.cpp field.h cell.h coords.h
	g++ -c field.cpp
cell.o: cell.cpp cell.h coords.h
	g++ -c cell.cpp
coords.o: coords.cpp coords.h field.h
	g++ -c coords.cpp
clean:
	rm -rf *.o