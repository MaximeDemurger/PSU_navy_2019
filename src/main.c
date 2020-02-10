/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "../include/navy.h"

int main(int ac, char **av)
{
    if (ac < 2)
        return 84;
    if (navy(av) == 84)
        return 84;
    return 0;
}