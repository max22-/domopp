all: domopp
.PHONY: clean

domopp: domopp.o clock.o
	g++ domopp.o clock.o -o domopp -lncurses -lpthread

domopp.o: domopp.cpp
	g++ -c domopp.cpp -o domopp.o -Wall

clock.o: clock.cpp
	g++ -c clock.cpp -o clock.o -Wall

clean:
	rm -rf *.o
	rm -rf domopp
