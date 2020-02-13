/*
** EPITECH PROJECT, 2019
** my atoi
** File description:
** my_atoi
*/

#include <stdlib.h>

int my_atoi(char const *stack)
{
    int printer = 0;
    int mult = 1;
    int n = my_strlen(stack) - 1;

    if (stack[0] == '-') {
        while (n >= 1) {
            printer = printer + (stack[n] - 48) * mult;
            n--;
            mult = mult * 10;
        }
        printer = printer * (-1);
    } else {
        while (n >= 0) {
            printer = printer + (stack[n] - 48) * mult;
            n--;
            mult = mult * 10;
        }
    }
    return (printer);
}
