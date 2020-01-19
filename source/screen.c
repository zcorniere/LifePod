/*
** PROJECT, 2020
** LifePod
** File description:
** source/screen.c
*/

#include "screen.h"

static void rebox_scr(scr_t *scr)
{
    if (scr == NULL)
        return;
    box(scr->event, ACS_VLINE, ACS_HLINE);
    box(scr->cmd, ACS_VLINE, ACS_HLINE);
    box(scr->status, ACS_VLINE, ACS_HLINE);
}

static void remove_win(scr_t *scr)
{
    if (scr == NULL)
        return;
    delwin(scr->event);
    delwin(scr->cmd);
    delwin(scr->status);
}

scr_t *new_scr(void)
{
    scr_t *screen = malloc(sizeof(scr_t));

    screen->event = subwin(stdscr, 6*LINES / 8, 3 * COLS/4, 0, 0);
    screen->cmd = subwin(stdscr, 2*LINES/8 + 1, 3*COLS/4, 6*LINES/8, 0);
    screen->status = subwin(stdscr, LINES, COLS/4, 0, 3*COLS/4);
    screen->rebox_scr = &rebox_scr;
    screen->remove_win = &remove_win;
    return(screen);
}

