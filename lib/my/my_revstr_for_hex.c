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

char *my_revstr_for_hex(char *str)
{
    int i = 0;
    int p1 = 0;
    int p2 = (my_strlen(str)) - 1;
    char p3;

    while (p2 > p1) {
        p3 = str[p1];
        str[p1] = str[p2];
        str[p2] = p3;
        p1++;
        p2--;
    }
    my_putstr(str);
}
