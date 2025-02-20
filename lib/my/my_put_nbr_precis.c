/*
** EPITECH PROJECT, 2024
** my_precisionnbr2.c
** File description:
** versionutile
*/

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_precisition2(int nb, int presition)
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

int my_put_nbr_precis(int nb, int presition)
{
    int i = nb;
    int j = 0;

    while (i > 9) {
        i = i / 10;
        j++;
    }
    while ((presition - 2) >= j) {
        my_precisition2(0, presition);
        presition--;
    }
    my_precisition2(nb, presition);
}
