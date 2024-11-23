/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** task07
*/

#include "../../include/my.h"
#include <unistd.h>

static int how_many_digit(int power)
{
    int exp = 1;

    while (power > 10) {
        power /= 10;
        exp++;
    }
    return exp;
}

int upper_ten(int nb)
{
    long int power = 10;
    int rest = 0;
    int i = 1;

    while (power <= nb) {
        power = power * 10;
        i++;
    }
    power /= 10;
    while (i != 0) {
        rest = nb % power;
        nb /= power;
        my_putchar(48 + nb);
        nb = rest;
        power /= 10;
        i--;
    }
    return 0;
}

int under_ten(int nb)
{
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    my_putchar(48 + nb);
    return 0;
}

int is_neg(int nb)
{
    if (nb == -2147483648) {
        nb = (nb * -1) / 10;
        my_putchar('-');
        upper_ten(nb);
        my_putchar('8');
    } else {
        nb *= -1;
        my_putchar('-');
        upper_ten(nb);
    }
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb > 9) {
        upper_ten(nb);
    }
    if (nb <= 9 && nb >= 0) {
        under_ten(nb);
    }
    if (nb < 0) {
        is_neg(nb);
    }
    return how_many_digit(nb);
}
