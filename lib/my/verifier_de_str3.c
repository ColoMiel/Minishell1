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

int verifier_de_str3(va_list list, char str, char str2, int *compteur)
{
    switch (str) {
    case 'n':
        my_put_nbr_de_caractere(va_arg(list, char *));
        break;
    case 'e':
        my_sci_not(va_arg(list, double), 0);
        break;
    case 'E':
        my_sci_not_majuscule(va_arg(list, double), 0);
        break;
    }
}
