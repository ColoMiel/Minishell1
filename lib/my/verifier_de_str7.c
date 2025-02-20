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

int verifier_de_str7(va_list list, char str, char str2, int *compteur)
{
    switch (str) {
    case 'l':
    case 'L':
        if (str2 == 'o') {
            my_put_octal(va_arg(list, long unsigned int));
            *compteur = 1;
            return *compteur;
        }
        if (str2 == 'u') {
            my_put_nbr_dec(va_arg(list, long unsigned int));
            *compteur = 1;
            return *compteur;
        }
    default:
        return 84;
        break;
    }
}
