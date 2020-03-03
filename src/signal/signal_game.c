/*
** EPITECH PROJECT, 2020
** signal_game
** File description:
** signal game
*/

#include <stdio.h>
#include "navy.h"

utils_t utils;

int send_signal(utils_t *utils, char *str)
{
    char a = 'A';
    char b = '1';

    while (a <= str[0]) {
        kill(utils->pid->enemy_pid, SIGUSR1);
        usleep(5000);
        a++;
    }
    kill(utils->pid->enemy_pid, SIGUSR2);
    usleep(5000);
    while (b <= str[1]) {
        kill(utils->pid->enemy_pid, SIGUSR1);
        usleep(5000);
        b++;
    }
    kill(utils->pid->enemy_pid, SIGUSR2);
    usleep(5000);
    return 0;
}

void game_signal_one(int signal, siginfo_t *info, void *x)
{
    static int change = 0;

    if (signal == SIGUSR1) {
        if (change == 0) {
            printf("letter %d\n", utils.receive_letter);
            utils.receive_letter++;
        } else if (change == 1) {
            printf("number %d\n", utils.receive_number);
            utils.receive_number++;
        }
    } else if (signal == SIGUSR2) {
        change++;
        if (change == 2) {
            change = 0;
        }
    }
    usleep(25000);
}

int get_signal_usr1(utils_t *utils)
{
    struct sigaction get_signal;

    get_signal.sa_sigaction = game_signal_one;
    sigemptyset(&get_signal.sa_mask);
    get_signal.sa_flags = 0;
    sigaction(SIGUSR1, &get_signal, 0);
    pause();
    return 0;
}