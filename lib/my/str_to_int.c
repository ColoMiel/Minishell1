/*
** EPITECH PROJECT, 2024
** inteur.c
** File description:
** str to int
*/

#include "my.h"

int my_str_to_int(char *str)
{
    int nb = 0;
    int i = 0;
    int sign = 1;

    while (str[i] == '0') {
        return 0;
    }
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return nb * sign;
}
