#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <deque>
#include <utility>
#include <mutex>

class Console
{
public:
    static Console& getInstance();
    Console(const Console&) = delete;
    Console(Console&&) = delete;
    Console& operator=(const Console&) = delete;
    Console& operator=(const Console&&) = delete;
    void println(std::string subject, std::string msg);

private:
    Console();
    ~Console();
    std::deque<std::pair<std::string, std::string>> buffer;
    unsigned long lines;
    std::mutex consoleMutex;
};

#endif // CONSOLE_H
