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

int verifier_de_str8(va_list list, char str, char str2, int *compteur)
{
    switch (str) {
    case 'l':
    case 'L':
        if (str2 == 'x') {
            my_put_nbr_hexa_minuscule(va_arg(list, long int));
            *compteur = 1;
            return *compteur;
        }
        if (str2 == 'X') {
            my_put_nbr_hexa_majuscule(va_arg(list, long int));
            *compteur = 1;
            return *compteur;
        }
    default:
        return 84;
        break;
    }
}
