#include "Screen.hpp"
#include <curses.h>

Screen::Screen() :
    event_({ 7 * LINES / 10, 7 * COLS / 10, 0, 0, true, ACS_VLINE, ACS_HLINE, true, "Event"}),
    cmd_({ 3 * LINES /10 + 1, 7 * COLS / 10, 7 * LINES / 10, 0, true, ACS_VLINE, ACS_HLINE, true, "Command"}),
    status_({LINES, 3 * COLS / 10, 0, 7 * COLS / 10, true, ACS_VLINE, ACS_HLINE, true, "Status"})
{}

Screen::~Screen()
{
    endwin();
}

void Screen::refreshW()
{
    event_.refresh();
    cmd_.refresh();
    status_.refresh();
}

void Screen::titleW(const bool r)
{
    event_.title(r);
    cmd_.title(r);
    status_.title(r);
}

void Screen::boxW(const bool r)
{
    event_.box(r);
    cmd_.box(r);
    status_.box(r);
}

void Screen::clearW(const bool r)
{
    event_.clear(r);
    cmd_.clear(r);
    status_.clear(r);
}


void Screen::displayShipStatus(const Ship &s, const bool r)
{
    status_.print(2, 1, "Colon :");
    printLoadbar(std::pair<int, int>(3, 1), s.getColon(), 1000);
    status_.print(4, 1, "%04i | 1000", s.getColon());
    status_.print(6, 1, "Landing :");
    printLoadbar(std::pair<int, int>(7, 1), s.getLanding(), 100);
    status_.print(8, 1, "%03i | 100", s.getLanding());
    status_.print(10, 1, "Building :");
    printLoadbar(std::pair<int, int>(11, 1), s.getBuild(), 100);
    status_.print(12, 1, "%03i | 100", s.getBuild());
    status_.print(14, 1, "Athmosphere :");
    printLoadbar(std::pair<int, int>(15, 1), s.getAtm(), 100);
    status_.print(16, 1, "%03i | 100", s.getAtm());
    status_.print(18, 1, "Gravity :");
    printLoadbar(std::pair<int, int>(19, 1), s.getGrav(), 100);
    status_.print(20, 1, "%03i | 100", s.getGrav());
    status_.print(22, 1, "Temperature :");
    printLoadbar(std::pair<int, int>(23, 1), s.getTemp(), 100);
    status_.print(24, 1, "%03i | 100", s.getTemp());
    status_.print(26, 1, "Water :");
    printLoadbar(std::pair<int, int>(27, 1), s.getWater(), 100);
    status_.print(28, 1, "%03i | 100", s.getWater());
    status_.print(30, 1, "Ressources :");
    printLoadbar(std::pair<int, int>(31, 1), s.getRes(), 100);
    status_.print(32, 1, "%03i | 100", s.getRes());
    if (r == true)
        status_.refresh();
}

void Screen::printShip(const bool r)
{
    int x = 0;
    int y = 0;

    getmaxyx(event_.getWindow(), y, x);
    event_.print(y - 15, x - 63, "                    `. ___");
    event_.print(y - 14, x - 63, "                    __,' __`.                _..----....____");
    event_.print(y - 13, x - 63, "        __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'");
    event_.print(y - 12, x - 63, "  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'");
    event_.print(y - 11, x - 63, ",'________________                          \\`-._`-','");
    event_.print(y - 10, x - 63, " `._              ```````````------...___   '-.._'-:");
    event_.print(y - 9, x - 63, "    ```--.._      ,.                     ````--...__\\-.");
    event_.print(y - 8, x - 63, "            `.--. `-`                       ____    |  |`");
    event_.print(y - 7, x - 63, "              `. `.                       ,'`````.  ;  ;`");
    event_.print(y - 6, x - 63, "                `._`.        __________   `.      \\'__/`");
    event_.print(y - 5, x - 63, "                   `-:._____/______/___/____`.     \\  `");
    event_.print(y - 4, x - 63, "                              |       `._    `.    \\");
    event_.print(y - 3, x - 63, "                               `._________`-.   `.   `.___");
    event_.print(y - 2, x - 63, "                                                  `------'`");
    if (r == true)
        event_.refresh();
}

void Screen::printLoadbar(const std::pair<int, int> coord, \
                          const int value, const int max, const bool r)
{
    const int bar_size = getmaxx(status_.getWindow()) - 4;
    const int coord_ = (value * bar_size) / max;
    std::string bar;

    bar.resize(bar_size + 1);
    bar[bar_size] = '\0';
    for (int i = 0; i < bar_size; i++)
        bar[i] = '-';
    for (int i = 0; i < coord_ && bar[i] != '\0'; i++)
        bar[i] = '#';
    status_.print(coord.first, coord.second, "[%s]", bar.c_str());
    if (r == true)
        status_.refresh();
}

void Screen::displayEventTxt(const std::vector<std::string> &e, const bool r)
{
    event_.clear(false);
    event_.box(false);
    event_.title(false);
    this->printShip(false);
    for (long unsigned int i = 1; i - 1 < e.size(); i++) {
        event_.print(i + 1, 2, e.at(i - 1));
    }
    if (r == true)
        event_.refresh();
}

void Screen::initScreen()
{
    initscr();
    noecho();
    curs_set(false);
    clear();
    cbreak();
    keypad(stdscr, true);
}
