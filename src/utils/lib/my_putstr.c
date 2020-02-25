/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "navy.h"

int my_putstr(char const *str)
{
    if (!str)
        return 84;
    write(1, str, my_strlen(str));
    return 0;
}