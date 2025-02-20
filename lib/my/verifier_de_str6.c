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

int verifier_de_str6(va_list list, char str, char str2, char str3)
{
    int presition;

    switch (str) {
    case '.':
        if (str3 == 'd' || str3 == 'i') {
            presition = str2 - 48;
            my_put_nbr_precis(va_arg(list, int), presition);
            break;
        }
    }
}
