/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** my_isneg.c
*/

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_put_nbr(int nb)
{
    char *negatif = "-";

    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb < 0 && nb >= -9) {
        nb = nb * (-1);
        my_putchar(*negatif);
        my_putchar(nb + 48);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    if (nb < -9) {
        nb = nb * (-1);
        my_putchar(*negatif);
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
}
