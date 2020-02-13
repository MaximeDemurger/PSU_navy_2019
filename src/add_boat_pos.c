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

int find_car(int *line, int *col, char a, char b)
{
    int alpha = 65;
    int nbr = 49;

    *line = 2;
    *col = 2;
    while (alpha < 72 && alpha != a) {
        *col += 2;
        alpha++;
    }
    while (nbr < 57 && nbr != b) {
        *line += 1;
        nbr++;
    }
    return 0;
}

char **add_letter(char a, char b, int boatSize, char **map)
{
    int line;
    int col;
    char *boat = convert_to_string(boatSize);

    find_car(&line, &col, a, b);
    printf("%s\n", map[line]);
    if (a < b) {
        while (a < b) {
            map[line][col] = boat[0];
            a++;
            col += 2;
        }
    } else if (a > b) {
        while (a > b) {
            map[line][col] = boat[0];
            b++;
            col -= 2;
        }
    }
    return map;
}

char **add_nbr(int *array, int boatSize, char **tab, char **map)
{
    int line;
    int col;
    char *boat = convert_to_string(boatSize);

    printf("%s\n", boat);
    find_car(&line, &col, tab[1][0], tab[1][1]);
    printf("%s  %c\n", map[line], boat[0]);
    if (array[0] < array[1]) {
        while (array[0] < array[1]) {
            map[line][col] = boat[0];
            array[0]++;
            line++;
        }
    } else if (array[0] > array[1]) {
        while (array[0] > array[1]) {
            map[line][col] = boat[0];
            array[1]++;
            line++;
        }
    }
    return map;
}

char **add_in_pos(char **tab, int boatSize, char **map)
{
    int first = tab[1][1] - 48;
    int second = tab[2][1] - 48;
    int array[2];

    array[0] = first;
    array[1] = second;
    if ((tab[1][0] == tab[2][0]) && first != second) {
        map = add_nbr(array, boatSize, tab, map);
    } else if ((tab[1][0] != tab[2][0]) && first == second) {
        map = add_letter(tab[1][0], tab[2][0], boatSize, map);
    }
    return map;
}

char **put_on_map(char *str, char **map)
{
    int boatSize = str[0] - 48;
    char **tab = NULL;

    tab = my_str_to_word_array(str, ':');
    map = add_in_pos(tab, boatSize, map);
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