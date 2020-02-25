/*
** EPITECH PROJECT, 2020
** signal_game
** File description:
** signal game
*/

#include <stdio.h>
#include "navy.h"

int send_signal(utils_t *utils, char *str)
{
    char a = 'A';
    int j = 0;

    while (a != str[0]) {
        kill(utils->pid->enemy_pid, 10);
        usleep(5000);
        ++a;
    }
    kill(utils->pid->enemy_pid, 12);
    usleep(5000);
    while (j != str[1] + 48) {
        kill(utils->pid->enemy_pid, 10);
        usleep(5000);
        ++j;
    }
    kill(utils->pid->enemy_pid, 12);
    usleep(5000);
    return 0;
}

void game_signal_two(int signal, utils_t *utils)
{
    static int change = 0;

    if (signal == 10) {
        if (change == 0)
            utils->receive_letter++;
        else if (change == 1)
            utils->receive_number++;
    } else if (signal == 12) {
        change++;
        if (change == 2) {
            change = 0;
        }
    }
    usleep(25000);
}

void game_signal_one(utils_t *utils)
{
    printf("receive\n");
    usleep(25000);
}

int get_signal_usr2(utils_t *utils)
{
    struct sigaction get_signal;

    get_signal.sa_handler = &game_signal_two;
    get_signal.sa_flags = SA_NODEFER;
    sigemptyset(&get_signal.sa_mask);
    sigaction(SIGUSR2, &get_signal, 0);
    sigaction(SIGUSR1, &get_signal, 0);
    pause();
    return 0;
}

int get_signal_usr1(utils_t *utils)
{
    struct sigaction get_signal;

    get_signal.sa_handler = &game_signal_one;
    get_signal.sa_flags = SA_NODEFER;
    sigemptyset(&get_signal.sa_mask);
    sigaction(SIGUSR2, &get_signal, 0);
    sigaction(SIGUSR1, &get_signal, 0);
    pause();
    return 0;
}