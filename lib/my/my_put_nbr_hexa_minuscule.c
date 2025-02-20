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

int my_put_nbr_hexa_minuscule(unsigned int nb)
{
    int compteur = nb;
    int j = 0;
    char *stokeur = malloc(sizeof(int) * 20);

    while (nb != -1) {
        compteur = nb % 16;
        if (compteur > 9 && compteur < 16) {
            compteur = compteur + 87;
            stokeur[j] = compteur;
            j++;
        }
        nb /= 16;
        if (compteur <= 9) {
            compteur = compteur + 48;
            stokeur[j] = compteur;
            j++;
        }
    }
    my_revstr_for_hex(stokeur);
}
