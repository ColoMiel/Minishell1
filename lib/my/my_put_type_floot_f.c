/*
** EPITECH PROJECT, 2024
** printf
** File description:
** versionutile
*/

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_precisition(double b, int a, int presition)
{
    while (presition > 0) {
        if (b < presition) {
            b = b * 10;
            my_put_nbr((int)b);
            a = (int)b;
            b = b - a;
            presition--;
        } else
            my_put_nbr(0);
    }
}

int my_put_type_floot_f(double nb, int presition)
{
    int a = (int)nb;
    double b = nb - a;

    my_put_nbr(a);
    if (b) {
        my_putchar('.');
        my_precisition(b, a, presition);
    } else {
        return 0;
    }
}
