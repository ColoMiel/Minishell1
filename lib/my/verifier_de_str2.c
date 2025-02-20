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

int verifier_de_str2(va_list list, char str, char str2, int *compteur)
{
    switch (str) {
    case 'u':
        my_put_nbr_dec(va_arg(list, unsigned int));
        break;
    case 'x':
        my_put_nbr_hexa_minuscule(va_arg(list, int));
        break;
    case 'X':
        my_put_nbr_hexa_majuscule(va_arg(list, int));
        break;
    case 'f':
    case 'F':
        my_put_floot_f(va_arg(list, double));
        break;
    }
}
