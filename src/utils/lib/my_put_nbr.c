/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/

#include "navy.h"

int my_put_nbr(int nb)
{
    int stock = nb;
    int i = 1;

    if (nb < 0 && nb != -2147483648) {
        my_putchar('-');
        nb = nb * (-1);
        stock = stock * (-1);
    } if (nb == -2147483648) {
        if (write(1, "-2147483648", 11) == -1)
            return 84;
        return 0;
    } while (stock >= 10) {
        stock = stock / 10;
        i = i * 10;
    }
    while (i >= 1) {
        my_putchar(nb / i + 48);
        nb = nb % i;
        i = i / 10;
    }
    return 0;
}
