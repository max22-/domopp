all: domopp
.PHONY: clean

domopp: domopp.o clock.o console.o mqtt.o mpd.o light.o computer.o macros.o
	g++ domopp.o clock.o console.o mqtt.o mpd.o light.o computer.o macros.o -o domopp -lncurses -lpthread -lmosquittopp

domopp.o: domopp.cpp clock.h console.h mqtt.h mpd.h light.h macros.h secret.h
	g++ -c domopp.cpp -o domopp.o -Wall

clock.o: clock.cpp clock.h
	g++ -c clock.cpp -o clock.o -Wall

console.o: console.cpp console.h
	g++ -c console.cpp -o console.o -Wall

mqtt.o: mqtt.cpp mqtt.h
	g++ -c mqtt.cpp -o mqtt.o -Wall

mpd.o: mpd.cpp mpd.h
	g++ -c mpd.cpp -o mpd.o -Wall

light.o: light.cpp light.h
	g++ -c light.cpp -o light.o -Wall
	
computer.o: computer.cpp computer.h
	g++ -c computer.cpp -o computer.o -Wall

macros.o: macros.cpp macros.h console.h mpd.h light.h computer.h
	g++ -c macros.cpp -o macros.o -Wall

clean:
	rm -rf *.o
	rm -rf domopp
