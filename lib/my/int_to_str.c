/*
** EPITECH PROJECT, 2024
** int_to_str.c
** File description:
** trnasf int en str
*/

#include "my.h"

char *my_int_to_str(int num)
{
    char *str;
    int len = 0;
    int temp = num;
    int i;

    while (temp >= 1) {
        temp /= 10;
        len++;
    }
    str = malloc(len + 1);
    str[len] = '\0';
    for (i = len - 1; i >= 0; i--) {
        str[i] = (num % 10) + '0';
        num /= 10;
    }
    return str;
}
