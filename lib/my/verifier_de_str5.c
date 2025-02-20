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

int verifier_de_str5(va_list list, char str, char str2, char str3)
{
    int presition;

    switch (str) {
    case '.':
        if (str3 == 'f' || str3 == 'F') {
            presition = str2 - 48;
            my_put_type_floot_f(va_arg(list, double), presition);
            break;
        }
        if (str3 == 'e') {
            presition = str2 - 48;
            my_sci_not(va_arg(list, double), presition);
            break;
        }
        if (str3 == 'E') {
            presition = str2 - 48;
            my_sci_not_majuscule(va_arg(list, double), presition);
            break;
        }
    }
}
