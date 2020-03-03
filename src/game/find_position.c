/*
** EPITECH PROJECT, 2020
** find position
** File description:
** find position
*/

#include "navy.h"
#include <stdio.h>

utils_t utils;

int display_hit(int hit)
{
    char letter = utils.receive_letter + 65;

    if (hit == 0)
        my_printf("%c%d: missed\n", letter, utils.receive_number);
    if (hit == 1)
        my_printf("%c%d: hit\n", letter, utils.receive_number);
    utils.receive_letter = 0;
    utils.receive_number = 0;
    return 0;
}

int hit_or_not(utils_t *utils, int line, int col)
{
    if (utils->hit == 0)
        utils->enemy_position[line][col] = 'o';
    if (utils->hit == 1)
        utils->enemy_position[line][col] = 'x';
    return 0;
}

int touch_board(utils_t *utils, int line, int col)
{
    if (utils->my_position[line][col] == '.') {
        utils->my_position[line][col] = 'o';
        utils->hit = 0;
    } else {
        utils->my_position[line][col] = 'x';
        utils->hit = 1;
    }
    return 0;
}

int find_position(int *line, int *col)
{
    int letter = utils.receive_letter;
    int number = utils.receive_number;
    
    *col = 2;
    *line = 1;
    while (letter > 0) {
        *col += 2;
        letter--;
    }
    while (number > 0) {
        *line += 1;
        number--;
    }
    return 0;
}