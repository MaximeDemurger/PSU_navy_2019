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

int global_var;

void handler(int signal, siginfo_t *info, void *x)
{
    my_putstr("\nenemy connected\n\n");
    //utils->pid->enemy_pid = info->si_pid;
    usleep(5000);
    global_var = info->si_pid;
}

int serveur(utils_t *utils)
{
    struct sigaction s;

    utils->pid->my_pid = getpid();
    if (my_putstr("my_pid: ") == 84
    || my_put_nbr(utils->pid->my_pid) == 84
    || my_putchar('\n') == 84
    || my_putstr("waiting for enemy connection...\n") == 84)
        return 84;
    s.sa_sigaction = handler;
    s.sa_flags = SA_SIGINFO;
    sigemptyset(&s.sa_mask);
    sigaction(SIGUSR1, &s, 0);
    pause();
    utils->pid->enemy_pid = global_var;
    return 0;
}

int enemy_pos(char **argv, utils_t *utils)
{
    if (!argv) {
        return 84;
    }
    utils->pid->my_pid = getpid();
    utils->pid->enemy_pid = my_atoi(argv[1]);
    if (my_putstr("my_pid: ") == 84
    || my_put_nbr(utils->pid->my_pid) == 84
    || (kill(utils->pid->enemy_pid, SIGUSR1) == -1)
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