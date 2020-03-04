/*
** EPITECH PROJECT, 2020
** win
** File description:
** win
*/

#include "navy.h"

int win = 0;

int win_player(utils_t *utils)
{
    int x = 0;
    int y = 0;

    utils->win = 0;
    while (utils->my_position[y] != NULL) {
        x = 0;
        while (utils->my_position[y][x] != '\0') {
            if (utils->my_position[y][x] >= 1
                && utils->my_position[y][x] <= 9) {
                utils->win = 1;
                return 0;
            }
            x++;
        }
        y++;
    }
    return 0;
}

int print_win(void)
{
    if (win == 2) {
        my_printf("I won\n");
        return 1;
    }
    win = 0;
    return 0;
}

void get_win(int signal)
{
    if (signal == SIGUSR1) {
        win++;
        usleep(5000);
    }
}

int get_win_player(void)
{
    struct sigaction get_win;

    get_win.sa_handler = &get_win;
    get_win.sa_flags = 0;
    sigemptyset(&get_win.sa_mask);
    sigaction(SIGUSR1, &get_win, 0);
    pause();
    if (print_win() == 1)
        return 1;
    return 0;
}

int send_win(utils_t *utils)
{
    win_player(utils);
    if (utils->win == 0) {
        kill(utils->pid->enemy_pid, SIGUSR1);
        usleep(5000);
    } else {
        kill(utils->pid->enemy_pid, SIGUSR1);
        usleep(5000);
        kill(utils->pid->enemy_pid, SIGUSR1);
        usleep(5000);
        my_printf("Enemy won\n");
    }
    return 0;
}