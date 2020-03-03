/*
** EPITECH PROJECT, 2020
** waiting for player
** File description:
** player move 
*/

#include "navy.h"
#include <stdio.h>

int waiting_for_player(utils_t *utils)
{
    int line;
    int col;

    get_signal_usr1();
    find_position(&line, &col);
    touch_board(utils, line, col);
    display_hit(utils->hit);
    send_touch(utils);
    return 0;
}