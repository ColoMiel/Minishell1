/*
** EPITECH PROJECT, 2024
** my_print_alpha
** File description:
** day 3, task 1
** my_print_alpha.c
*/


#include "my.h"
#include <string.h>
#include <stdio.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest);

    while (src[i] != '\0'){
        dest[len + i] = src[i];
        i++;
    }
    dest[i + len] = '\0';
    return dest;
}
