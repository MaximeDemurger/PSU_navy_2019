/*
** EPITECH PROJECT, 2020
** player move
** File description:
** player move
*/

#include "navy.h"
#include <stdio.h>
#include <stdlib.h>

int check_input(char const *str)
{
    int i = 0;

    if (my_strlen(str) > 3)
        return -1;
    if (my_char_isalpha(str[0]) != 0)
        return -1;
    if (my_char_isnum(str[1]) != 0)
        return -1;
    return 0;
}

int player_move(utils_t *utils)
{
    char *str = NULL;

    my_putstr("\nattack: ");
    while ((str = get_next_line(0))) {
        if (check_input(str) < 0) {
            my_putstr("wrong position\n");
            free(str);
            my_putstr("attack: ");
        }
    }
    prepa_signal.sa_handler = &handlering
    sigaction(SIGUSR2, &prepa_signal, 0);
        printf("Send with success\n\n");
}