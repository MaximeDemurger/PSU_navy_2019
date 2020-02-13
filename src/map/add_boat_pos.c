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
    while (alpha < 72 && alpha + 48 != a) {
        *col += 2;
        alpha++;
    }
    while (nbr < 57 && nbr + 48 != b) {
        *line += 1;
        nbr++;
    }
    return 0;
}

char **add_letter(char a, char b, int boatSize, char **map)
{
    int line = 0;
    int col = 0;

printf("La map vaut : %p\n", map);
printf("la première ligne vaut : %p\n", map[line]);
    find_car(&line, &col, a, b);
    printf("line : %d et col : %d\n", line, col);
    if (a < b) {
        while (a < b) {
            printf("Avant y'avait ça : %c\n", map[line][col]);
            map[line][col] = (char)boatSize + 48;
            a++;
            col += 2;
        }
    } else if (a > b) {
        while (a > b) {
            map[line][col] = (char)boatSize + 48;
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

    find_car(&line, &col, tab[1][0], tab[1][1]);
    if (array[0] < array[1]) {
        while (array[0] < array[1]) {
            map[line][col] = boatSize + 48;
            array[0]++;
            line++;
        }
    } else if (array[0] > array[1]) {
        while (array[0] > array[1]) {
            map[line][col] = boatSize + 48;
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
        map = add_letter(tab[1][0], tab[1][1], boatSize, map);
    }
    return map;
}