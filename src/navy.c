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

int navy(char **av)
{
    char **my_pos = NULL;
    int fd = 0;
    char **tab = NULL;

    if (av[1] == NULL) {
        return 84;
    }
    fd = open(av[1], O_RDONLY);
    my_pos = map_navy();
    if (!my_pos)
        return 84;
    if ((tab = check_files(fd)) == NULL)
        return 84;
    my_pos = add_boat_pos(my_pos, tab);
    return 0;
}