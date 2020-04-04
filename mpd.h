#ifndef MPD_H
#define MPD_H

#include "console.h"

class MPD
{
public:
    MPD();
    void add(std::string song);
    void next();
    void volumeUp();
    void volumeDown();
    void toggle();
    void play();
    void loadPlaylist(std::string playlist);

private:
    Console& console;
};

#endif // MPD_H
