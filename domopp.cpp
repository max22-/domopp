#include <iostream>
#include <ncurses.h>
#include <thread>
#ifdef __arm__
#include <wiringPi.h>
#endif
#include "clock.h"
#include "console.h"
#include "mqtt.h"
#include "mpd.h"
#include "light.h"
#include "macros.h"
#include "secret.h"

Mqtt mqtt(mqttHost);

enum class Mode {DEFAULT, PLAYLISTS, PODCASTS, MACROS};



int main() {
    bool exit = false;
    Mode mode = Mode::DEFAULT;
    Console& console = Console::getInstance();
    MPD mpd;


    std::cout << '\a' << std::endl; // beep
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    timeout(100);

    #ifdef __arm__
        wiringPiSetup();
    #endif

    std::thread th1(cornerClock);

    mqtt.begin();

    while(!exit) {
        int rc = mqtt.loop();
        if(rc) {
            mqtt.reconnect();
            console.println("MQTT", "Disconnected. Reconnecting to server...");
        }
        int c = getch();
        switch(c) {
            case 'q':
                exit = true;
                break;
            case '\t':
                mode = Mode::DEFAULT;
                console.println("Mode", "DEFAULT");
                break;
            case '/':
                mode = Mode::PLAYLISTS;
                console.println("Mode", "PLAYLISTS");
                break;
            case '*':
                mode = Mode::PODCASTS;
                console.println("Mode", "PODCASTS");
                break;
            case 127:
                mode = Mode::MACROS;
                console.println("Mode", "MACROS");
                break;
        }

        switch(mode) {
            case Mode::DEFAULT:
                switch (c) {
                    case '0':
                        mpd.next();
                        break;
                    case '.':
                        mpd.volumeDown();
                        break;
                    case '\n':
                        mpd.toggle();
                        break;
                    case '1':
                        light::bedroom::on();
                        break;
                    case '2':
                        light::bedroom::off();
                        break;
                    case '3':
                        mpd.volumeUp();
                        break;
                }
                break;
            case Mode::PLAYLISTS:
                switch(c) {

                }
                break;
            case Mode::PODCASTS:
                switch (c) {

                }
                break;
            case Mode::MACROS:
                switch (c) {
                    case '0': {
                        std::thread th2(macro::goToBed);
                        th2.join();
                        break;
                    }
                    case '1': {
                        macro::hifiPower();
                        break;
                    }
                }
                break;
        }
    }
    endwin();
    puts("\a"); // beep
    return 0;
}
