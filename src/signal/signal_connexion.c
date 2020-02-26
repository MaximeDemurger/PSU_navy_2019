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

<<<<<<< HEAD
void handler(int signal, utils_t *utils, siginfo_t *info)
=======
void handler(void)
>>>>>>> 28fb50650114bbb687356332061c58b6f1511044
{
    my_putstr("\nenemy connected\n\n");
    //utils->pid->enemy_pid = info->si_pid;
    usleep(5000);
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
    new.sa_handler = (void*)handler;
    sigemptyset(&new.sa_mask);
    new.sa_flags = SA_SIGINFO;
    while (sigaction(SIGUSR1, &new, 0) < 0)
        usleep(1000);
    pause();
    return 0;
}

int enemy_pos(char **argv, utils_t *utils)
{
    if (!argv || !utils) {
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
    if (!argc || !argv || !utils)
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