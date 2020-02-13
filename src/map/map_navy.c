/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** map_navy.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "navy.h"

char **map_navy(void)
{
    char **map = malloc(sizeof(char *) * 11);

    if (!map)
        return NULL;
    map[0] = my_strdup(" |A B C D E F G H");
    map[1] = my_strdup("-+---------------");
    map[2] = my_strdup("1|. . . . . . . .");
    map[3] = my_strdup("2|. . . . . . . .");
    map[4] = my_strdup("3|. . . . . . . .");
    map[5] = my_strdup("4|. . . . . . . .");
    map[6] = my_strdup("5|. . . . . . . .");
    map[7] = my_strdup("6|. . . . . . . .");
    map[8] = my_strdup("7|. . . . . . . .");
    map[9] = my_strdup("8|. . . . . . . .");
    map[10] = NULL;
    return map;
}