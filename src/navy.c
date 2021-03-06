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

utils_t *utils;

int check_error(int ac, char **av)
{
    if (av[1] == NULL || !utils || !utils->pid)
        return 84;
    if (ac == 3) {
        if (av[2] == NULL)
            return 84;
    }
    return 0;
}

int navy(int ac, char **av)
{
    utils->pid = malloc(sizeof(my_pid_t));
    int fd = 0;

    if (check_error(ac, av) == 84)
        return 84;
    if (check_positions_boats(ac, av, fd, utils) == 84) {
        write(2, "Wrong map\n", 10);
        return 84;
    }
    if (enemy_connection(ac, av, utils) == 84 || game_loop(utils, ac) == 84)
        return 84;
    return 0;
}