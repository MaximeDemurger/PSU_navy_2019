/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "../include/navy.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 2 || ac == 3) {
        if (navy(ac, av) == 84)
            return 84;
    } else {
        return 84;
    }
    return 0;
}