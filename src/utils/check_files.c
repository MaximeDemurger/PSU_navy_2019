/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check_file.c
*/

#include "../../include/navy.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int check_boat_size(char *str)
{
    int boatSize = 0;
    char **tab = NULL;

    if (!str)
        return 84;
    if (!(tab = my_str_to_word_array(str, ':')))
        return 84;
    boatSize = tab[0][0] - 48;
    if (compare_pos(tab, boatSize) == 84)
        return 84;
    return 0;
}

int check_map_diag(char *str)
{
    int digit = 0;

    if (str[2] != str[5])
        digit = 1;
    if (digit == 1 && str[3] != str[6])
        return (-1);
    return 0;
}

int check_map_validity(char const *str, int size)
{
    if ((str[0] != size + 48) && str[1] != ':' &&
        (str[2] > 'H' || str[2] < 'A') && (str[3] > '8' || str[3] < '1') &&
        str[4] != ':' && (str[5] > 'H' || str[5] < 'A') &&
        (str[6] > '8' || str[6] < '1'))
        return -1;
    return 0;
}

char **check_files(int fd)
{
    char *str = NULL;
    char **tab = malloc(sizeof(char *) * 6);
    int i = 0;
    int size = 2;

    if (!tab)
        return NULL;
    while ((str = get_next_line(fd))) {
        if (check_map_validity(str, size) == -1 ||
            check_map_diag(str) == -1)
            return NULL;
        if (check_boat_size(str) == 84)
            return NULL;
        tab[i] = my_strdup(str);
        i++;
        size++;
        free(str);
    }
    tab[i] = NULL;
    return tab;
}