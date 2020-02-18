/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** add_boat_pos.c
*/

#include "../include/navy.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int find_pos(int *line, int *col, char letterMap, char numberMap)
{
    char letter = 'A';
    char number = '1';

    *line = 1;
    *col = 2;
    while (letter != letterMap) {
        letter++;
        *col += 2;
    }
    while (number <= numberMap) {
        *line += 1;
        number++;
    }
    return 0;
}

char **add_letter(char **tab, utils_t *utils, char **map)
{
    int line = 0;
    int col = 0;

    find_pos(&line, &col, tab[1][0], tab[1][1]);
    if (tab[1][0] < tab[2][0]) {
        while (tab[1][0] < tab[2][0] + 1) {
            map[line][col] = utils->boatSize + 48;
            tab[1][0]++;
            col += 2;
        }
    } else if (tab[1][0] > tab[2][0]) {
        while (tab[1][0] + 1 > tab[2][0]) {
            map[line][col] = utils->boatSize + 48;
            tab[2][0]++;
            col -= 2;
        }
    }
    return map;
}

char **add_nbr(utils_t *utils, char **tab, char **map)
{
    int line;
    int col;

    find_pos(&line, &col, tab[1][0], tab[1][1]);
    if (utils->first_pos < utils->second_pos) {
        while (utils->first_pos < utils->second_pos + 1) {
            map[line][col] = utils->boatSize + 48;
            utils->first_pos++;
            line++;
        }
    } else if (utils->first_pos >utils->second_pos) {
        while (utils->first_pos + 1 > utils->second_pos) {
            map[line][col] = utils->boatSize + 48;
            utils->second_pos++;
            line++;
        }
    }
    return map;
}

char **add_in_pos(char **tab, utils_t *utils, char **map)
{
    utils->first_pos = tab[1][1] - 48;
    utils->second_pos = tab[2][1] - 48;

    if ((tab[1][0] == tab[2][0]) && utils->first_pos != utils->second_pos) {
        map = add_nbr(utils, tab, map);
    } else if ((tab[1][0] != tab[2][0])
        && utils->first_pos == utils->second_pos) {
        map = add_letter(tab, utils, map);
    }
    return map;
}