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

int my_put_octal(unsigned int nb)
{
    if (nb >= 0 && nb <= 7) {
        my_putchar(nb + 48);
    }
    if (nb > 7) {
        my_put_octal(nb / 8);
        my_putchar(nb % 8 + 48);
    }
}
