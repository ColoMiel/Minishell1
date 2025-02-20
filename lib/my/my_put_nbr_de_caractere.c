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
#include "my.h"

int my_put_nbr_de_caractere(char *phrase)
{
    int count = 0;
    int i = 0;

    while (phrase[i] != '\0') {
        count++;
        i++;
    }
    return (count);
}
