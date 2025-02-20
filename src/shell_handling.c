/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-hatim.ouaadi
** File description:
** shell_handling
*/

#include "../lib/my/my.h"

static void print_env(char ***env, struct every_struct *index,
    char **every_word)
{
    if (every_word[1]) {
        index->shell_status.exit_code = 127;
        return;
    }
    for (int i = 0; (*env)[i] != NULL; i++) {
        my_printf("%s\n", (*env)[i]);
    }
}

char **remove_env2(char ***env, int len, int i)
{
    for (int j = i; j < len - 1; j++) {
        (*env)[j] = (*env)[j + 1];
    }
    (*env)[len - 1] = NULL;
    return *env;
}

char **remove_env(char **env, char *var)
{
    int len = 0;

    for (; env[len]; len++);
    for (int i = 0; i < len; i++) {
        if (my_strncmp(env[i], var, my_strlen(var)) == 0
            && env[i][my_strlen(var)] == '=') {
            free(env[i]);
            remove_env2(&env, len, i);
            return env;
        }
    }
    return env;
}

static int verif_setenv2(char **every_word,
    struct every_struct *index, char ***env)
{
    for (int i = 0; every_word[1][i] != '\0'; i++) {
        if (every_word[1][i] == '"') {
            my_printf("Unmatched '\"'.\n");
            return 1;
        }
        if (!((every_word[1][i] >= 'A' && every_word[1][i] <= 'Z') ||
            (every_word[1][i] >= 'a' && every_word[1][i] <= 'z') ||
            (every_word[1][i] >= '0' && every_word[1][i] <= '9') ||
            every_word[1][i] == '_')) {
            my_printf("setenv: Variable name must"
                " contain alphanumeric characters.\n");
            return 1;
        }
    }
}

static int verif_setenv(char **every_word,
    struct every_struct *index, char ***env)
{
    if (!every_word[1]) {
        print_env(env, index, every_word);
        return 0;
    }
    if (!((every_word[1][0] >= 'A' && every_word[1][0] <= 'Z') ||
        (every_word[1][0] >= 'a' && every_word[1][0] <= 'z') ||
        every_word[1][0] == '_')) {
        my_printf("setenv: Variable name must"
            " begin with a letter or underscore.\n");
        return 1;
    }
    if (verif_setenv2(every_word, index, env) == 1)
        return 1;
    return 0;
}

int shell_handling2(char *command, char **every_word, char ***env,
    struct every_struct *index)
{
    if (my_strcmp(every_word[0], "setenv") == 0) {
        if (verif_setenv(every_word, index, env) == 1) {
            index->shell_status.exit_code = 1;
            return 1;
        }
        if (every_word[1] && every_word[2])
            *env = update_env((*env), every_word[1], every_word[2]);
        if (every_word[1] && !every_word[2])
            *env = update_env((*env), every_word[1], "");
        return 1;
    }
    if (my_strcmp(every_word[0], "unsetenv") == 0 && every_word[1]) {
        *env = remove_env((*env), every_word[1]);
        return 1;
    }
    if (my_strcmp(command, "exit") == 0) {
        my_printf("exit\n");
        exit(index->shell_status.exit_code);
    }
    return 0;
}

int shell_handling(char *command, char **every_word, char ***env,
    struct every_struct *index)
{
    if (my_strcmp(command, "cd") == 0 || my_strcmp(every_word[0], "cd") == 0) {
        cd_handling(command, every_word, env, index);
        return 1;
    }
    if (my_strcmp(command, "clear") == 0 && !every_word[1]) {
        my_printf("\033[H\033[J");
        return 1;
    }
    if (my_strcmp(every_word[0], "env") == 0) {
        print_env(env, index, every_word);
        return 1;
    }
    if (shell_handling2(command, every_word, env, index) == 1) {
        return 1;
    } else if (shell_handling2(command, every_word, env, index) == 0) {
        return 0;
    }
}
