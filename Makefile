all: domopp
.PHONY: clean

podpad: podpad.o
	g++ podpad.o -o podpad -lncurses

podpad.o: podpad.c
	gcc -c podpad.c -o podpad.o -Wall

clean:
	rm -rf *.o
	rm -rf domopp
