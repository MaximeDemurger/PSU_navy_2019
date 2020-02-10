/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** map_navy.c
*/

#include <stddef.h>
#include <stdlib.h>

char **map_navy(void)
{
    char **map = malloc(sizeof(char *) * 11);

    map[0] = " |A B C D E F G H";
    map[1] = "-+---------------";
    map[2] = "1|. . . . . . . .";
    map[3] = "2|. . . . . . . .";
    map[4] = "3|. . . . . . . .";
    map[5] = "4|. . . . . . . .";
    map[6] = "5|. . . . . . . .";
    map[7] = "6|. . . . . . . .";
    map[8] = "7|. . . . . . . .";
    map[9] = "8|. . . . . . . .";
    map[10] = NULL;
    return map;
}