/*
** EPITECH PROJECT, 2024
** printf
** File description:
** versionutile
*/

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int lanceur_de_str(va_list list, char str, char str2, int *compteur)
{
    verifier_de_str(list, str, str2, compteur);
    verifier_de_str2(list, str, str2, compteur);
    verifier_de_str3(list, str, str2, compteur);
    verifier_de_str4(list, str, str2, compteur);
    verifier_de_str7(list, str, str2, compteur);
    verifier_de_str8(list, str, str2, compteur);
}

int lanceur_de_str2(va_list list, char str, char str2, char str3)
{
    verifier_de_str5(list, str, str2, str3);
    verifier_de_str6(list, str, str2, str3);
}

int my_printf(const char *format, ...)
{
    int comp;
    va_list list;

    if (format == 0 || format[0] == '\0')
        return 0;
    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        comp = 0;
        if (format[i] == '%' && format[i + 1] == '.') {
            lanceur_de_str2(list, format[i + 1], format[i + 2], format[i + 3]);
            i = i + 4;
        }
        if (format[i] == '%' && format[i + 1] != '.') {
            lanceur_de_str(list, format[i + 1], format[i + 2], &comp);
            i = i + 1 + comp;
        } else
            my_putchar(format[i]);
    }
    va_end(list);
}
