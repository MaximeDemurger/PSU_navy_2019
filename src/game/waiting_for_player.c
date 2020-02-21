/*
** EPITECH PROJECT, 2020
** waiting for player
** File description:
** player move 
*/

#include "navy.h"
#include <stdio.h>

int modifying_map(utils_t *utils, char a, char b)
{
    int col = 2;
    int line = 2;

    while (utils->my_position[0][col] != a)
        col++;
    while (utils->my_position[line][0] != b)
        line++;
    if (utils->my_position[line][col] != '.') {
        utils->my_position[line][col] = 'x';
        my_printf("%c%c: hit\n", a, b);
    } else {
        utils->my_position[line][col] = 'o';
        my_printf("%c%c: missed\n", a, b);
    }
    utils->receive_number = 0;
    utils->receive_letter = 0;
    return 0;
}

int interpret_signal(utils_t *utils)
{
    char a = 'A';
    char b = '2';

    while (utils->receive_number > 0)
        b++;
    modifying_map(utils, utils->receive_letter, b);
    return 0;
}

int waiting_for_player(utils_t *utils)
{
    get_signal_usr1(utils);
    interpret_signal(utils);
    return 0;
}