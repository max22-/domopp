#include "mpd.h"
#include <cstdlib>
#include <string>

MPD::MPD() : console(Console::getInstance())
{

}

void MPD::add(std::string song)
{
    console.println("MPD", "add " + song);
    std::system(("mpc add " + song).c_str());
}


void MPD::next()
{
    console.println("MPD", "next");
    std::system("mpc next");
}


void MPD::volumeUp()
{
    console.println("MPD", "volume up");
    std::system("mpc volume +5");
}

void MPD::volumeDown()
{
    console.println("MPD", "volume down");
    std::system("mpc volume -5");
}

void MPD::toggle()
{
    console.println("MPD", "toggle");
    std::system("mpc toggle");
}

void MPD::play()
{
    console.println("MPD", "play");
    std::system("mpc play");
}

void MPD::loadPlaylist(std::string playlist)
{
    console.println("MPD", "play");
    std::system((std::string("mpc load ") + playlist).c_str());
}
