/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.c
*/

#include "../include/navy.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int navy(int ac, char **av)
{
    utils_t *utils = malloc(sizeof(utils_t));
    utils->pid = malloc(sizeof(my_pid_t));
    int fd = 0;

    if (av[1] == NULL || !utils)
        return 84;
    if (enemy_connection(ac, av, utils) == 84 ||
    check_positions_boats(ac, av, fd, utils) == 84)
        return 84;
    if (game_loop(utils, ac) == 84)
        return 84;
<<<<<<< HEAD
=======
    if (ac == 2) {
        if (game_loop(utils) == 84)
            return 84;
    } else {
        if (game_loop_2(utils) == 84)
            return 84;
    }
>>>>>>> 28fb50650114bbb687356332061c58b6f1511044
    return 0;
}