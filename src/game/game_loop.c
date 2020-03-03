/*
** EPITECH PROJECT, 2020
** game loop
** File description:
** game loop
*/

#include <stdbool.h>
#include <stdio.h>
#include "navy.h"

int game_loop(utils_t *utils, int ac)
{
    bool game_on = true;
    int turn = 0;
    int both_player_played = 2;

    if (ac == 3)
        turn = 1;
    while (game_on == true) {
        if (both_player_played == 2) {
            if (print_map(utils) == 84)
                return 84;
            both_player_played = 0;
        } if (turn == 0) {
            player_move(utils);
            turn++;
        } else {
            waiting_for_player(utils);
            turn = 0;
        }
        both_player_played++;
    }
    return 0;
}