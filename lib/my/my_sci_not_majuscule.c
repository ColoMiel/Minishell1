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

int my_neg_sci1(double b, int precistion, int nb_max)
{
    int i = 0;
    int a;
    double c;

    if (b < 0)
        b = b * (-1);
    while (b <= 1) {
        b = b * 10;
        i++;
    }
    a = (int)b;
    c = b - a;
    my_put_nbr_notation_sci1(a);
    my_sci_not2_majuscule(b, precistion, nb_max, c);
    my_posuer_de_puiss21(i);
}

int my_put_nbr_notation_sci1(int nb)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
        my_putchar('.');
    }
    if (nb > 9) {
        my_put_nbr_notation_sci1(nb / 10);
        my_putchar(nb % 10 + 48);
    }
}

int my_put_nbr_avec_01(int nb)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar('0');
        my_putchar(nb + 48);
    }
}

int my_posuer_de_puiss1(int i)
{
    int j = 0;

    if (i < 0) {
        i = i * (-1);
    }
    my_putchar('E');
    my_putchar('+');
    while (i >= 9) {
        i = i / 10;
        j++;
    }
    if (j < 10) {
        my_put_nbr_avec_01(j);
    } else
        my_put_nbr(j);
}

int my_sci_not_majuscule(double nb, int precistion)
{
    int a = (int)nb;
    double b = (nb - a) * (-1);
    int c = abs(a);
    int j = 1;

    if (nb < 0)
        nb = nb * (-1);
        my_putchar('-');
    for (int i = 0; i <= precistion; i++)
        j = j * 10;
    if (c != 0) {
        while (c >= j)
            c = c / 10;
        while (c < j / 10)
            c = c * 10;
    }
    if (nb < 1 && nb > 0)
        my_neg_sci1(b, precistion, j);
    else
        my_put_nbr_notation_sci1(c) && my_posuer_de_puiss1(a);
}
