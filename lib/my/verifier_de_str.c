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
#include <string.h>
#include <unistd.h>
#include "my.h"

int verifier_de_str(va_list list, char str, char str2, int *compteur)
{
    switch (str) {
    case 'd':
    case 'i':
        my_put_nbr(va_arg(list, int));
        break;
    case 's':
        my_putstr(va_arg(list, char const *));
        break;
    case 'c':
        my_putchar(va_arg(list, int));
        break;
    case 'o':
        my_put_octal(va_arg(list, unsigned int));
        break;
    case '%':
        my_putchar('%');
        break;
    }
}
