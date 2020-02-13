/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my_strdup.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *str)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    if (!dest)
        return NULL;
    while (str[i]) {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}