/*
** EPITECH PROJECT, 2020
** game loop
** File description:
** game loop
*/

#include <stdbool.h>
#include "navy.h"

<<<<<<< HEAD
int game_loop(utils_t *utils, int ac)
=======
int game_loop_2(utils_t *utils)
{
    bool game_on = true;

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

int game_loop(utils_t *utils)
>>>>>>> 28fb50650114bbb687356332061c58b6f1511044
{
    bool game_on = true;

    if (ac == 3)
        turn = 1;
    while (game_on == true) {
        if (print_map(utils) == 84)
            return 84;
        if (turn == 0) {
            player_move(utils);
            turn++;
        } else {
            waiting_for_player(utils);
            turn = 0;
        }
    }
    return 0;
}