/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.c
*/

#include "../include/navy.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int navy(char **av)
{
    utils_t *utils = malloc(sizeof(utils_t));
    int fd = 0;
    char **tab = NULL;

    if (av[1] == NULL)
        return 84;
    fd = open(av[1], O_RDONLY);
    utils->my_position = map_navy();
    utils->enemy_position = map_navy();
    if (!utils->my_position || !utils->enemy_position || fd < 0)
        return 84;
    if ((tab = check_files(fd)) == NULL)
        return 84;
    utils->my_position = add_boat_pos(utils->my_position, tab);
    while (*utils->my_position) {
        printf("%s\n", *utils->my_position++);
    }
    return 0;
}