/*
** EPITECH PROJECT, 2020
** game loop
** File description:
** game loop
*/

#include <stdbool.h>
#include "navy.h"

int game_loop_2(utils_t *utils, int ac)
{
    bool game_on = true;
    int turn = 0;

    if (print_map(utils) == 84)
            return 84;
    while (game_on == true) {
        if (print_map(utils) == 84)
            return 84;
        waiting_for_player(utils);
        player_move(utils);
        
    }
    return 0;
}

int game_loop(utils_t *utils, int ac)
{
    bool game_on = true;
    int turn = 0;

    while (game_on == true) {
        if (print_map(utils) == 84)
            return 84;
        player_move(utils);
        waiting_for_player(utils);
    }
    return 0;
}