#include "console.h"
#include <ncurses.h>

Console::Console()
{

}

Console::~Console()
{

}

Console& Console::getInstance()
{
    static Console instance;
    return instance;
}

void Console::println(std::string subject, std::string msg)
{
    consoleMutex.lock();
    buffer.push_front(msg);
    while(buffer.size() > static_cast<unsigned long>(LINES-1))
        buffer.pop_back();
    int i = 0;
    for(auto it = buffer.crbegin(); it != buffer.crend(); ++it) {
        mvprintw(1+i++, 0, ("[" + subject + "] " + *it).c_str());
        clrtoeol();
    }
    refresh();
    consoleMutex.unlock();
}
