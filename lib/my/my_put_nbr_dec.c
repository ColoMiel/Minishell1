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

int my_put_nbr_dec(unsigned int nb)
{
    int count = 0;

    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb > 9) {
        my_put_nbr_dec(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    if (nb < 0) {
        count = 4294967296 - nb;
        my_put_nbr_dec(count);
    }
}
