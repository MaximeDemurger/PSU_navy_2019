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

int serveur(void)
{
    struct sigaction new;
    pid_t pid = getpid();

    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putchar('\n');
    my_putstr("waiting for enemy connection...\n");
    new.sa_handler = &handler;
    sigemptyset(&new.sa_mask);
    new.sa_flags = 0;
    while (sigaction(SIGUSR1, &new, 0) < 0)
        sleep(1);
    pause();
    return 0;
}

int enemy_pos(char **argv)
{
    pid_t pid_enemy = my_atoi(argv[2]);
    kill(pid_enemy, SIGUSR1);
    my_putstr("my_pid: ");
    my_put_nbr(pid_enemy);
    my_putstr("\nsuccessfully connected\n\n");
    return 0;
}

int enemy_connection(int argc, char **argv)
{
    if (argc < 3) {
        serveur();
    }
    if (argc == 3) {
        enemy_pos(argv);
    }
    return 0;
}