/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "navy.h"

int print_map(utils_t *utils)
{
    int i = 0;

    if (my_putstr("my_position:\n") == 84)
        return 84;
    while (utils->my_position[i]) {
        if (my_putstr(utils->my_position[i++]) == 84
        || my_putchar('\n') == 84)
            return 84;
    }
    my_putchar('\n');
    if (my_putstr("enemy_position:\n") == 84)
        return 84;
    i = 0;
    while (utils->enemy_position[i]) {
        if (my_putstr(utils->enemy_position[i++]) == 84 ||
        my_putchar('\n') == 84)
            return 84;
    }
    return 0;
}

char **put_on_map(char *str, char **map)
{
    utils_t *utils = malloc(sizeof(utils_t));
    char **tab = NULL;

    if (!utils || !str || !map)
        return NULL;
    utils->boatSize = str[0] - 48;
    tab = my_str_to_word_array(str, ':');
    if (!tab)
        return NULL;
    map = add_in_pos(tab, utils, map);
    return map;
}

char **add_boat_pos(char **map, char **tab)
{
    int i = 0;

    while (tab[i]) {
        map = put_on_map(tab[i], map);
        i++;
    }
    return map;
}