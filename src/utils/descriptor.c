/*
** EPITECH PROJECT, 2019
** descriptor
** File description:
** 2018
*/

#include "navy.h"

int descriptor(void)
{
    my_putstr("USAGE\n");
    my_putstr("  ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("        first_player_pid:  only for the 2nd player.");
    my_putstr("  pid of the first player.\n");
    my_putstr("        navy_positions:   file representing the positions");
    my_putstr(" of the ships.\n");
    return 0;
}