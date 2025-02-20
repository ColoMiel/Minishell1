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

int my_sci_not2(double b, int precistion,
    int nb_max, double nb_virgul)
{
    int a = 0;
    int c = 0;
    int d = 0;

    nb_max = nb_max / 10;
    while (a <= precistion) {
        c = nb_virgul * nb_max;
        a++;
    }
    d = (int)c;
    my_put_nbr(d);
}

int my_posuer_de_puiss2(int i)
{
    int j = 0;

    if (i < 0) {
        i = i * (-1);
    }
    my_putchar('e');
    my_putchar('-');
    while (i >= 9) {
        i = i / 10;
        j++;
    }
    if (j < 10) {
        my_put_nbr_avec_0(i);
    } else
        my_put_nbr(j);
}
