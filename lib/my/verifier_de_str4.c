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

int verifier_de_str4(va_list list, char str, char str2, int *compteur)
{
    switch (str) {
    case 'l':
    case 'L':
        if (str2 == 'd' || str2 == 'i') {
            my_put_nbr_long_int(va_arg(list, long long int));
            *compteur = 1;
            return *compteur;
        }
        break;
    case 'h':
        if (str2 == 'd' || str2 == 'i') {
            my_put_nbr_short_int(va_arg(list, int));
            *compteur = 1;
            return *compteur;
        }
    default:
        return 84;
        break;
    }
}
