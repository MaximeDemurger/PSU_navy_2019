/*
** EPITECH PROJECT, 2020
** signal
** File description:
** signal
*/

#include "../include/navy.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int signal)
{
    my_putstr("\nenemy connected\n\n");
}

int serveur(utils_t *utils)
{
    struct sigaction new;

    utils->pid->my_pid = getpid();
    if (my_putstr("my_pid: ") == 84
    || my_put_nbr(utils->pid->my_pid) == 84
    || my_putchar('\n') == 84
    || my_putstr("waiting for enemy connection...\n") == 84)
        return 84;
    new.sa_handler = &handler;
    sigemptyset(&new.sa_mask);
    new.sa_flags = 0;
    while (sigaction(SIGUSR1, &new, 0) < 0)
        usleep(1000);
    pause();
    return 0;
}

int enemy_pos(char **argv, utils_t *utils)
{
    if (!argv) {
        return 84;
    }
    utils->pid->my_pid = getpid();
    utils->pid->enemy_pid = my_atoi(argv[1]);
    if (kill(utils->pid->enemy_pid, SIGUSR1) == -1
    || my_putstr("my_pid: ") == 84
    || my_put_nbr(utils->pid->my_pid) == 84
    || my_putstr("\nsuccessfully connected\n\n") == 84)
        return 84;
    return 0;
}

int enemy_connection(int argc, char **argv, utils_t *utils)
{
    if (!argc)
        return 84;
    if (argc < 3) {
        if (serveur(utils) == 84)
            return 84;
    }
    if (argc == 3) {
        if (enemy_pos(argv, utils) == 84)
            return 84;
    }
    return 0;
}