/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-hatim.ouaadi
** File description:
** minishell_base
*/

#include "../lib/my/my.h"

char **update_env(char **env, char *var, char *value)
{
    int len = 0;
    char *new_var = malloc(my_strlen(var) + my_strlen(value) + 2);
    char **new_env;

    my_strcpy(new_var, var);
    my_strcat(new_var, "=");
    my_strcat(new_var, value);
    for (; env[len]; len++) {
        if (my_strncmp(env[len], var, my_strlen(var)) == 0
        && env[len][my_strlen(var)] == '=') {
            env[len] = new_var;
            return env;
        }
    }
    new_env = malloc(sizeof(char *) * (len + 2));
    for (int i = 0; i < len; i++)
        new_env[i] = env[i];
    new_env[len] = new_var;
    new_env[len + 1] = NULL;
    return new_env;
}

char **copy_env(char **env)
{
    int i;
    char **new_env;

    for (i = 0; env[i] != NULL; i++);
    new_env = malloc(sizeof(char *) * (i + 2));
    if (!new_env)
        return NULL;
    for (i = 0; env[i] != NULL; i++)
        new_env[i] = my_strdup(env[i]);
    new_env[i] = NULL;
    return new_env;
}

static void exec_command(char **commands, char ***env,
    struct every_struct *index)
{
    char **every_word = NULL;
    char **cleaned_words = NULL;

    for (int i = 0; commands[i] != NULL; i++) {
        every_word = my_str_to_word_array(commands[i]);
        cleaned_words = clean_array(every_word);
        if (shell_handling(commands[i], cleaned_words, &(*env), index) == 1)
            continue;
        finding_function(cleaned_words, (*env), index);
    }
}

int start_shell(int argc, char **argv, char **env)
{
    char *command;
    char **commands;
    struct every_struct index;

    index.shell_status.exit_code = 0;
    while (6) {
        index.cmp.cmp_for_cd = 0;
        display_prompt(env);
        command = read_command();
        if (command[my_strlen(command) - 1] == '\n')
            command[my_strlen(command) - 1] = '\0';
        if (command[0] == '\0')
            continue;
        commands = my_str_to_word_array_delim(command, ';');
        exec_command(commands, &env, &index);
    }
    return 0;
}

int main(int argc, char **argv, char **env)
{
    char **new_env;
    char *poubelle = "/usr/share/locale/%L/LC_MESSAGES/%N."
        "cat:/usr/share/locale/%l/LC_MESSAGES/%N.cat";

    if (argc != 1) {
        return 1;
    }
    new_env = copy_env(env);
    new_env = update_env(new_env, "NLSPATH", poubelle);
    start_shell(argc, argv, new_env);
}
