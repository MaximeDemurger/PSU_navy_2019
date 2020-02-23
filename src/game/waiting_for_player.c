/*
** EPITECH PROJECT, 2020
** waiting for player
** File description:
** player move 
*/

#include "navy.h"
#include <stdio.h>

void handlering(int signal)
{
    printf("receive %d\n\n", signal);
}

int waiting_for_player(utils_t *utils)
{
    struct sigaction new;

    my_putstr("\nwaiting for attack...\n");
    new.sa_handler = &handlering;
    while (sigaction(SIGUSR1, &new, 0) < 0)
        usleep(1000);
    kill(utils->pid->enemy_pid, SIGUSR1);
    pause();
    return (0);
}