/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** struct.h
*/

#ifndef PSU_NAVY_2019_STRUCT_H
#define PSU_NAVY_2019_STRUCT_H

#include <signal.h>

typedef struct my_pid
{
    pid_t my_pid;
    int enemy_pid;
    int global_value;
} my_pid_t;

typedef struct utils_s {
    int boatSize;
    int first_pos;
    int second_pos;
    char **my_position;
    char **enemy_position;
    char receive_letter;
    int receive_number;
    int boat;
    int hit;
    int hit;
    int letter;
    int number;
    my_pid_t *pid;
} utils_t;

#endif //PSU_NAVY_2019_STRUCT_H
