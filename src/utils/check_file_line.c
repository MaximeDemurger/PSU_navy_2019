/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check_file_line.c
*/

#include <unistd.h>
#include <fcntl.h>
#include "navy.h"

int check_positions_boats(int ac, char **av, int fd, utils_t *utils)
{
    char **tab = NULL;

    if (!av || !utils)
        return 84;
    if (ac < 3)
        fd = open(av[1], O_RDONLY);
    else
        fd = open(av[2], O_RDONLY);
    utils->my_position = map_navy();
    utils->enemy_position = map_navy();
    if (!utils->my_position || !utils->enemy_position || !fd)
        return 84;
    if ((tab = check_files(fd)) == NULL)
        return 84;
    utils->my_position = add_boat_pos(utils->my_position, tab);
    return 0;
}