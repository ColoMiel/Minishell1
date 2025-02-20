/*
** EPITECH PROJECT, 2024
** mmy_print_comb
** File description:
** day 3, task05
** my_print_comb.c
*/

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_strcpy1(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int my_strlen1(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;

    dest = malloc(sizeof(char) * ((my_strlen1(src)) + 1));
    my_strcpy1(dest, src);
    return dest;
}
