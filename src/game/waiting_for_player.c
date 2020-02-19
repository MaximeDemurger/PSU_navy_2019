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
    struct sigaction prepa_signal;

    my_putstr("\nwaiting for enemy's attack...\n");
    prepa_signal.sa_handler = &handlering;
    prepa_signal.sa_flags = SA_NODEFER;
    sigemptyset(&prepa_signal.sa_mask);
    sigaction(SIGUSR2, &prepa_signal, 0);
    sigaction(SIGUSR1, &prepa_signal, 0);
    pause();
    return (0);
}