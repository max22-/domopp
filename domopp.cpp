#include <iostream>
#include <ncurses.h>
#include <thread>
#include "clock.h"

int main() {
    bool exit = false;

    std::cout << '\a' << std::endl; // beep
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    std::thread th1(cornerClock);
    mvprintw(1, 0, "Connecting to MQTT broker...");
    clrtoeol();
    while(!exit) {
        int c = getch();
        switch (c) {
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    }
    endwin();
    puts("\a"); // beep
    return 0;
}
