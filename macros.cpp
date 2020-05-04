#include "macros.h"
#include <chrono>
#include <thread>
#include "console.h"
#include "mpd.h"
#include "light.h"
#include "computer.h"

namespace macro {

void goToBed()
{
    Console& console = Console::getInstance();
    MPD mpd;
    console.println("Macro", "Running goToBed");
    computer::shutdown();
    light::bedroom::off();
    light::livingroom::on();
    mpd.loadPlaylist("playlist3");
    const int hifiBootTime = 40;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    hifiPower();
    std::this_thread::sleep_for(std::chrono::milliseconds(hifiBootTime*1000));
    light::livingroom::off();
    mpd.play();
    for(int i=0; i<3;i++) {
        system("irsend send_once axd7676 KEY_SLEEP");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    console.println("Macro", "Finished running goToBed");
}

void hifiPower()
{
    system("irsend send_once axd7676 KEY_POWER");
}

void Marguerite()
{
    Console& console = Console::getInstance();
    MPD mpd;
    console.println("Macro", "Running Marguerite");
    mpd.add("CDs/youtube/Richard-Cocciante-Marguerite.mp3");
    const int hifiBootTime = 40;
    hifiPower();
    std::this_thread::sleep_for(std::chrono::milliseconds(hifiBootTime*1000));
    mpd.play();
    for(int i=0; i<2;i++) {
        system("irsend send_once axd7676 KEY_SLEEP");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    console.println("Macro", "Finished running Marguerite");
}

}
