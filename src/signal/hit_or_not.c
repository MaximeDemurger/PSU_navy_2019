/*
** EPITECH PROJECT, 2020
** hit or not
** File description:
** hit or not
*/

#include "navy.h"
#include <stdio.h>

int touched = 0;

int find_own_hit(char *str, int *line, int *col)
{
    int letter = str[0] - 65;
    int number = str[1] - 48;

    *col = 2;
    *line = 1;
    while (letter > 0) {
        *col += 2;
        letter--;
    }
    while (number > 0) {
        *line += 1;
        number--;
    }
    return 0;
}

int check_hit(utils_t *utils, char *str)
{
    int line = 0;
    int col = 0;

    find_own_hit(str, &line, &col);
    if (touched == 2) {
        utils->enemy_position[line][col] = 'x';
        my_printf("%c%c: hit\n", str[0], str[1]);
    } else if (touched == 1) {
        utils->enemy_position[line][col] = 'o';
        my_printf("%c%c: missed\n", str[0], str[1]);
    }
    touched = 0;
    return 0;
}

void get_touched(int signal)
{
    if (signal == SIGUSR1) {
        touched++;
        usleep(5000);
    }
    usleep(25000);
}

int get_touch(void)
{
    struct sigaction get_touch;

    get_touch.sa_handler = &get_touched;
    get_touch.sa_flags = SA_NODEFER;
    sigemptyset(&get_touch.sa_mask);
    sigaction(SIGUSR1, &get_touch, 0);
    pause();
    return 0;
}

int send_touch(utils_t *utils)
{
    if (utils->hit == 0) {
        kill(utils->pid->enemy_pid, SIGUSR1);
        usleep(5000);
    } else {
        kill(utils->pid->enemy_pid, SIGUSR1);
        usleep(5000);
        kill(utils->pid->enemy_pid, SIGUSR1);
        usleep(5000);
    }
    return 0;
}