/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-hatim.ouaadi
** File description:
** clean
*/

#include "../lib/my/my.h"

static char *clean_str(char *str)
{
    int i = 0;
    int j = 0;
    char *cleaned = malloc(my_strlen(str) + 1);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            cleaned[j] = str[i];
            j++;
        }
    }
    cleaned[j] = '\0';
    return cleaned;
}

int is_valid_char(char c)
{
    if (c == '\0')
        return 0;
    if (c == ' ')
        return 0;
    if (c == '\t')
        return 0;
    return 1;
}

int should_count(char *str)
{
    for (int j = 0; str[j] != '\0'; j++) {
        if (is_valid_char(str[j]) == 1) {
            return 1;
        }
    }
    return 0;
}

int should_add_to_cleaned_array(char *str)
{
    for (int j = 0; str[j] != '\0'; j++) {
        if (is_valid_char(str[j]) == 1) {
            return 1;
        }
    }
    return 0;
}

char **clean_array(char **array)
{
    int count = 0;
    char **cleaned_array;
    int k = 0;

    for (int i = 0; array[i] != NULL; i++) {
        if (should_count(array[i]) == 1) {
            count++;
        }
    }
    cleaned_array = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; array[i] != NULL; i++) {
        if (should_add_to_cleaned_array(array[i]) == 1) {
            cleaned_array[k] = clean_str(array[i]);
            k++;
        }
    }
    cleaned_array[k] = NULL;
    return cleaned_array;
}
