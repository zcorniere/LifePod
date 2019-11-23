/*
** PROJECT, 2019
** lifepod
** File description:
** header
*/

#define _GNU_SOURCE
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "my_curse.h"
#include "parser.h"
#include "my.h"
#include "macros.h"

#ifndef LIFEPOD_H_
#define LIFEPOD_H_

#define COLON 1
#define ATM 2
#define GRAV 3
#define TEMP 4
#define WATER 5
#define RES 6
#define LAND 7
#define BUILD 8

#define OPT_ONE 'a'
#define OPT_TWO 'z'
#define OPT_THREE 'e'
#define OPT_FOUR 'r'
#define OPT_QUIT 'q'


#define EVENT_DIR "./event_data/"

typedef struct scr_s {
    WINDOW *event;
    WINDOW *cmd;
    WINDOW *status;
} scr_t;

typedef struct button_s {
    short system;
    unsigned int dmg;
    unsigned int max_mult;
    char *msg;
} button_t;

typedef struct event_s {
    char **tab;
    unsigned int nb_buttons;
    button_t **button;
} event_t;

typedef struct scan_s {
    unsigned int atm;
    unsigned int grav;
    unsigned int temp;
    unsigned int water;
    unsigned int res;
} scan_t;

typedef struct ship_s {
    unsigned int colon;
    scan_t *scan;
    unsigned int landing;
    unsigned int build;
} ship_t;

scan_t *alloc_scan(void);
ship_t *alloc_ship(void);
event_t *alloc_event(void);
button_t *alloc_button(void);
scr_t *build_scr_t(void);

int game(scr_t *scr, ship_t *ship, event_t **event);

void refresh_all(scr_t *scr);
void title_win(scr_t *scr);
void display_ship_status(WINDOW *scr, ship_t *ship);

void print_ship(WINDOW *win, int const y, int const x);

button_t *parse_button(char const * const buffer);
event_t *parse_event(char const *buffer);
event_t **load_all_event(void);

void free_tab(char **tab);
void free_event(event_t **event);

bool is_event_loaded(event_t *event);
int event_related(WINDOW *win, WINDOW *cmd, event_t *event);

bool is_good_input(unsigned int nb_buttons, char input);
int button_related(ship_t *ship, event_t *event);

#endif /*LIFEPOD_H_*/
