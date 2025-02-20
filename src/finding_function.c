/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-hatim.ouaadi
** File description:
** parsing_shell
*/

#include "../lib/my/my.h"

int signal_check(int status, struct every_struct *index)
{
    int cmp = 0;
    int signal_num;
    char *signal_msg;

    if (!isatty(STDIN_FILENO))
        cmp = 1;
    if (!WIFSIGNALED(status))
        return 0;
    signal_num = WTERMSIG(status);
    signal_msg = strsignal(signal_num);
    my_printf("%s\n", signal_msg);
    index->shell_status.exit_code = 128 + signal_num;
    if (cmp == 1)
        exit(128 + signal_num);
    return 128 + signal_num;
}

void finding_function2(char **every_word, char **env, char *execs)
{
    char *path = malloc(256);

    if (every_word[0][0] == '/' || every_word[0][0] == '.') {
        my_strcpy(path, every_word[0]);
    } else {
        my_strcpy(path, execs);
        my_strcat(path, "/");
        my_strcat(path, every_word[0]);
    }
    if (execve(path, every_word, env) == -1) {
        free(path);
        return;
    }
    free(path);
    exit(0);
}

void finding_function(char **every_word, char **env,
    struct every_struct *index)
{
    pid_t pid = fork();
    int status;
    char *all_exec = get_env_value(env, "PATH");
    char **alls_execs = my_str_to_word_array_delim(all_exec, ':');

    if (pid == -1)
        return;
    if (pid == 0) {
        for (int i = 0; alls_execs[i] != NULL; i++)
            finding_function2(every_word, env, alls_execs[i]);
        write(1, every_word[0], my_strlen(every_word[0]));
        write(1, ": Command not found.\n", 21);
        index->shell_status.exit_code = 1;
        exit(1);
    } else {
        wait(&status);
        if (WIFEXITED(status))
            index->shell_status.exit_code = WEXITSTATUS(status);
        signal_check(status, index);
    }
}
