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
    utils->letter = str[0] - 65;
    utils->number = str[1] - 48;

    printf("letter %d\n", utils->letter);
    printf("number %c\n", str[1]);
    while (utils->letter >= 0) {
        kill(utils->pid->enemy_pid, SIGUSR1);
        usleep(5000);
        utils->letter--;
        printf("letter\n");
        usleep(5000);
    }
    kill(utils->pid->enemy_pid, SIGUSR2);
    usleep(5000);
    while (utils->number > 0) {
        kill(utils->pid->enemy_pid, SIGUSR1);
        usleep(5000);
        utils->number--;
        printf("number\n");
    }
    kill(utils->pid->enemy_pid, SIGUSR2);
    usleep(5000);
}

void game_signal_one(int signal)
{
    static int change = 0;

    if (signal == SIGUSR1) {
        if (change == 0) {
            printf("letter %d\n", utils.receive_letter);
            utils.receive_letter++;
            usleep(25000);
        } else if (change == 1) {
            printf("number %d\n", utils.receive_number);
            utils.receive_number++;
            usleep(25000);
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

    get_signal.sa_handler = &game_signal_one;
    get_signal.sa_flags = SA_NODEFER;
    sigemptyset(&get_signal.sa_mask);
    sigaction(SIGUSR1, &get_signal, 0);
    sigaction(SIGUSR2, &get_signal, 0);
    pause();
    return 0;
}