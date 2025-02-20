/*
** EPITECH PROJECT, 2024
** printf
** File description:
** versionutile
*/

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"
#include <stdlib.h>

int my_put_floot_f(double nb)
{
    int a = (int)nb;
    float b = a - nb;
    int floot;

    my_put_nbr(a);
    my_putchar('.');
    floot = b * -1000000;
    my_put_nbr(floot);
}
