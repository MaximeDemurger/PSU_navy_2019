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

char **put_on_map(char *str, char **map)
{
    utils_t *utils = malloc(sizeof(utils_t));
    char **tab = NULL;

    if (!utils)
        return NULL;
    utils->boatSize = str[0] - 48;
    tab = my_str_to_word_array(str, ':');
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