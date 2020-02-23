#include "clock.h"
#include <ncurses.h>
#include <ctime>
#include <chrono>
#include <thread>

void cornerClock()
{
    time_t rawTime;
    struct tm* timeInfo;

    while(true) {
        time(&rawTime);
        timeInfo = localtime(&rawTime);
        mvprintw(0, COLS-8, "%02d:%02d:%02d", timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

}
