/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-hatim.ouaadi
** File description:
** shell
*/

#include "../lib/my/my.h"

void display_prompt(char **env)
{
    char *path = get_env_value(env, "PWD");

    if (!isatty(STDIN_FILENO))
        return;
    write(1, "\033[1;31mmy_shell_\033[1;36m[ψ<(ఠ ̭ ఠ)>ψ]>\033[0m", 49);
    write(1, "\033[1;35m", 8);
    if (path)
        write(1, path, my_strlen(path));
    write(1, "\033[0m", 5);
    write(1, "\033[1;31m: \033[0m", 14);
}

char *read_command(void)
{
    char *command = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&command, &len, stdin);
    if (read == -1) {
        write(1, "\n", 1);
        exit(0);
    }
    return command;
}
