/*
** EPITECH PROJECT, 2020
** waiting for player
** File description:
** player move 
*/

#include "navy.h"
#include <stdio.h>

int touch_board_enemies(utils_t *utils, int x, int y)
{
    if (utils->enemy_position[x][y] = '.') {
        utils->enemy_position[x][y] = 'o';
        utils->hit = 0;
    } else {
        utils->enemy_position[x][y] = 'x';
        utils->hit = 1;
    }
}

int find_position_enemies(utils_t *utils)
{
    int x = 1;
    int y = 1;
    int letter = 0;
    int number = 0;

    while (letter <= utils->receive_letter) {
        x += 2;
        letter++;
    }
    while (number <= utils->receive_number) {
        y++;
        number++;
    }
    touch_board_enemies(utils, x, y);
    return 0;
}

int touch_board(utils_t *utils, int x, int y)
{
    if (utils->my_position[x][y] = '.') {
        utils->my_position[x][y] = 'o';
        utils->hit = 0;
    } else {
        utils->my_position[x][y] = 'x';
        utils->hit = 1;
    }
}

int find_position(utils_t *utils)
{
    int x = 1;
    int y = 1;
    int number = 0;
    int letter = 0;

    while (letter <= utils->receive_letter) {
        x += 2;
        letter++;;
    }
    while (number != utils->receive_number) {
        y++;
        number++;
    }
    touch_board(utils, x, y);
    return 0;
}

int waiting_for_player(utils_t *utils)
{
    get_signal_usr1(utils);
    return 0;
}