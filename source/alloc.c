/*
** PROJECT, 2019
** lifepd
** File description:
** alloc
*/

#include "lifepod.h"

scan_t *alloc_scan(void)
{
    scan_t *ret = malloc(sizeof(scan_t));

    if (ret == NULL)
        return (NULL);
    ret->atm = 100;
    ret->grav = 100;
    ret->temp = 100;
    ret->water = 100;
    ret->res = 100;
    return (ret);
}

ship_t *alloc_ship(void)
{
    ship_t *ret = malloc(sizeof(ship_t));
    scan_t *scan = alloc_scan();

    if (ret == NULL || scan == NULL)
        return (NULL);
    ret->colon = 1000;
    ret->scan = scan;
    ret->landing = 100;
    ret->build = 100;
    return (ret);
}

event_t *alloc_event(void)
{
    event_t *ret = malloc(sizeof(event_t));

    if (ret == NULL)
        return (NULL);
    ret->system = 0;
    ret->dmg = 0;
    ret->max_mult = 0;
    ret->tab = NULL;
    ret->button = NULL;
    return (ret);
}

scr_t *build_scr_t(void)
{
    scr_t *screen = malloc(sizeof(scr_t));

    screen->event = subwin(stdscr, 6*LINES / 8, 3 * COLS/4, 0, 0);
    box(screen->event, ACS_VLINE, ACS_HLINE);
    screen->cmd = subwin(stdscr, 2*LINES/8 + 1, 3*COLS/4, 6*LINES/8, 0);
    box(screen->cmd, ACS_VLINE, ACS_HLINE);
    screen->status = subwin(stdscr, LINES, COLS/4, 0, 3*COLS/4);
    box(screen->status, ACS_VLINE, ACS_HLINE);
    return(screen);
}
