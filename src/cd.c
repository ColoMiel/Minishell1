/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-hatim.ouaadi
** File description:
** cd
*/

#include "../lib/my/my.h"

char *get_env_value(char **env, char *var)
{
    int len = my_strlen(var);

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], var, len) == 0 && env[i][len] == '=')
            return env[i] + len + 1;
    }
    return NULL;
}

char *cd_with_arg(char **env, char **every_word)
{
    return every_word[1];
}

char *cd_solo(char **env)
{
    char *path;
    char *home;
    char *env_doble;

    for (int i = 0; env[i] != NULL; i++) {
        env_doble = my_strdup(env[i]);
        home = strtok(env_doble, "=");
        if (my_strcmp(home, "HOME") == 0) {
            path = strtok(NULL, "\n");
            return path;
        }
    }
}

static void cd_handling3(char *filestat)
{
    struct stat dir;

    stat(filestat, &dir);
    if (!S_ISREG(dir.st_mode)) {
        my_printf("%s: No such file or directory.\n", filestat);
        return;
    }
    if (S_ISREG(dir.st_mode)) {
        my_printf("%s: Not a directory.\n", filestat);
        return;
    }
}

int cd_handling2(char *path, char ***env, char **every_word,
    struct every_struct *index)
{
    char newpwd[256];

    if (every_word[1] && my_strcmp(every_word[1], "-") == 0
        && index->cmp.cmp_for_cd == 0) {
        path = get_env_value(*env, "OLDPWD");
        if (!path) {
            my_printf(": No such file or directory.\n");
            index->shell_status.exit_code = 1;
            return 1;
        }
    } else if (every_word[1] && index->cmp.cmp_for_cd == 0)
        path = every_word[1];
    if (chdir(path) == -1) {
        cd_handling3(path);
        index->shell_status.exit_code = 1;
        return 1;
    }
    getcwd(newpwd, sizeof(newpwd));
    *env = update_env(*env, "PWD", newpwd);
    return 0;
}

void cd_handling(char *command, char **every_word, char ***env,
    struct every_struct *index)
{
    char *path = NULL;
    char oldpwd[256];

    getcwd(oldpwd, sizeof(oldpwd));
    if (every_word[2]) {
        my_printf("cd: Too many arguments.\n");
        index->shell_status.exit_code = 1;
        return;
    }
    if (!every_word[1] || my_strcmp(every_word[1], "~") == 0) {
        path = cd_solo(*env);
        index->cmp.cmp_for_cd = 1;
    }
    if (cd_handling2(path, env, every_word, index) == 0) {
        *env = update_env(*env, "OLDPWD", oldpwd);
    }
}
