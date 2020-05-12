CFLAGS=-Wall
LDFLAGS=-lncurses -lpthread -lmosquittopp -lwiringpi

all: domopp
.PHONY: clean

domopp: domopp.o clock.o console.o mqtt.o mpd.o light.o macros.o
	g++ domopp.o clock.o console.o mqtt.o mpd.o light.o macros.o -o domopp $(LDFLAGS)

domopp.o: domopp.cpp clock.h console.h mqtt.h mpd.h light.h macros.h secret.h
	g++ -c domopp.cpp -o domopp.o $(CFLAGS)

clock.o: clock.cpp clock.h
	g++ -c clock.cpp -o clock.o $(CFLAGS)

console.o: console.cpp console.h
	g++ -c console.cpp -o console.o $(CFLAGS)

mqtt.o: mqtt.cpp mqtt.h
	g++ -c mqtt.cpp -o mqtt.o $(CFLAGS)

mpd.o: mpd.cpp mpd.h
	g++ -c mpd.cpp -o mpd.o $(CFLAGS)

light.o: light.cpp light.h
	g++ -c light.cpp -o light.o $(CFLAGS)

macros.o: macros.cpp macros.h console.h mpd.h light.h
	g++ -c macros.cpp -o macros.o $(CFLAGS)

clean:
	rm -rf *.o
	rm -rf domopp
