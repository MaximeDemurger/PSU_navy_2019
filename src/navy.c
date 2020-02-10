/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.c
*/

#include "../include/navy.h"
#include <stdio.h>

int navy(char **av)
{
    char **map;

    map = map_navy();
    if (check_files(av) == 84)
        return 84;
    return 0;
}