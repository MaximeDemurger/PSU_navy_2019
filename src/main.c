/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "../include/navy.h"
#include <stdlib.h>

utils_t *utils;

int main(int ac, char **av)
{
    utils = malloc(sizeof(utils_t));
    if (ac == 2 || ac == 3) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            descriptor();
            return 0;
        } else if (navy(ac, av) == 84)
            return 84;
    } else {
        write(2, "Look at the help page: ./navy -h\n", 34);
        return 84;
    }
    return 0;
}