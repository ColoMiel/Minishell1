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

int my_getnbr(char const *str)
{
    int arret_de_ligne = 0;
    long int nombre = 0;
    int nombre_de_change = 0;
    int negatif = 1;

    for (int i = 0; str[i] != '\0' && arret_de_ligne == 0; i++) {
        if (str[i] >= 48 && str[i] <= 58 && str[i - 1] == 45) {
            negatif = negatif * (-1);
        }
        while (str[i] >= 48 && str[i] <= 57) {
            nombre_de_change = str[i] - 48;
            nombre = nombre * 10 + nombre_de_change;
            arret_de_ligne++;
            i++;
        }
    }
    if (nombre > 2147483647 || nombre < -2147483647) {
        my_putchar(0 + 48);
    } else
        my_put_nbr(nombre * negatif);
}
