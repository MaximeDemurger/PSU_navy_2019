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
    if (my_strlen(str) >= 3 || my_char_isalpha(str[0]) != 0 ||
        my_char_isnum(str[1]) != 0)
        return -1;
    return 0;
}

int player_move(utils_t *utils)
{
    char *str = NULL;

    utils->receive_letter = 0;
    utils->receive_number = 0;
    my_putstr("\nattack: ");
    while ((str = get_next_line(0)) != NULL) {
        if (check_input(str) < 0) {
            my_putstr("wrong position\n");
            free(str);
            my_putstr("attack: ");
        } else {
            send_signal(utils, str);
            get_touch();
            check_hit(utils, str);
            return 0;
        }
    }
    return 0;
}