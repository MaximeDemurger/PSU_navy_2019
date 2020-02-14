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

int compare_letter(char a, char b, int boatSize)
{
    int ascii_table = 0;

    if (a < b) {
        while (a < b) {
            a++;
            ascii_table++;
        }
        if (ascii_table + 1 != boatSize)
            return 84;
    } else if (a > b) {
        while (a > b) {
            b++;
            ascii_table++;
        }
        if (ascii_table + 1 != boatSize)
            return 84;
    }
    return 0;
}

int compare_nbr(int first, int second, int boatSize)
{
    int count = 1;

    if (first < second) {
        while (first < second) {
            count++;
            first++;
        }
        if (count != boatSize)
            return 84;
    } else if (first > second) {
        while (first > second) {
            count++;
            second++;
        }
        if (count != boatSize)
            return 84;
    }
    return 0;
}

int compare_pos(char **tab, int boatSize)
{
    int first = tab[1][1] - 48;
    int second = tab[2][1] - 48;

    if ((tab[1][0] == tab[2][0]) && first != second) {
        if (compare_nbr(first, second, boatSize) == 84)
            return 84;
    } else if ((tab[1][0] != tab[2][0]) && first == second) {
        if (compare_letter(tab[1][0], tab[2][0], boatSize) == 84)
            return 84;
    } else if ((tab[1][0] == tab[2][0]) && (first == second))
        return 84;
    return 0;
}

int checkBoat_size(char *str)
{
    int boatSize = 0;
    char **tab = NULL;

    if (str == NULL)
        return 84;
    if (!(tab = my_str_to_word_array(str, ':')))
        return 84;
    boatSize = tab[0][0] - 48;
    if (check_file_line(tab, boatSize) == 84)
        return 84;
    if (compare_pos(tab, boatSize) == 84)
        return 84;
    return 0;
}

char **check_files(int fd)
{
    char *str = NULL;
    char **tab = malloc(sizeof(char *) * 6);
    int i = 0;

    while ((str = get_next_line(fd))) {
        if (checkBoat_size(str) == 84)
            return NULL;
        tab[i] = my_strdup(str);
        i++;
        free(str);
    }
    tab[i] = NULL;
    return tab;
}