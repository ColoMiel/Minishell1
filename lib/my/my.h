/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** a
*/

#include <string.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#ifndef MY_
    #define MY_

struct shell_status {
    int exit_code;
};

struct cmp {
    int cmp_for_cd;
};

struct every_struct {
    struct shell_status shell_status;
    struct cmp cmp;
};


void display_prompt(char **env);
void finding_function(char **every_word, char **env,
    struct every_struct *index);
char *read_command(void);
int start_shell(int argc, char **argv, char **env);
void cd_handling(char *command, char **every_word, char ***env,
    struct every_struct *index);
char **update_env(char **env, char *var, char *value);
int shell_handling(char *command, char **every_word, char ***env,
    struct every_struct *index);
char **clean_array(char **array);
char *get_env_value(char **env, char *var);

char *my_int_to_str(int num);
int my_str_to_int(char *str);
int is_digit(const char *str);
int my_strncmp(const char *str1, const char *str2, int n);
int my_printf(const char *format, ...);
int my_getnbr(char const *str);
int my_put_nbr_precis(int nb, int presition);
int verifier_de_str(va_list list, char str, char str2, int *compteur);
int verifier_de_str2(va_list list, char str, char str2, int *compteur);
int verifier_de_str3(va_list list, char str, char str2, int *compteur);
int verifier_de_str4(va_list list, char str, char str2, int *compteur);
int verifier_de_str5(va_list list, char str, char str2, char str3);
int verifier_de_str6(va_list list, char str, char str2, char str3);
int verifier_de_str7(va_list list, char str, char str2, int *compteur);
int verifier_de_str8(va_list list, char str, char str2, int *compteur);
int my_put_nbr_notation_sci(int nb);
int my_posuer_de_puiss2(int i);
int my_put_nbr_avec_0(int nb);
int my_put_nbr_notation_sci1(int nb);
int my_posuer_de_puiss21(int i);
int my_sci_not(double nb, int precistion);
int my_sci_not2(double b, int precistion, int nb_max, double nb_virgul);
int my_sci_not_majuscule(double nb, int precistion);
int my_sci_not2_majuscule(double b, int precistion,
    int nb_max, double nb_virgul);
int my_put_type_floot_f(double nb, int presition);
char **my_str_to_word_array(char *str);
void my_putchar(char c);
int my_put_nbr_de_caractere(char *phrase);
int my_put_nbr(int nb);
int my_put_nbr_dec(unsigned int nb);
int my_put_floot_f(double nb);
int my_put_nbr_dec(unsigned int nb);
char *my_revstr_for_hex(char *str);
int my_put_nbr_hexa_majuscule(unsigned int nb);
int my_put_nbr_hexa_minuscule(unsigned int nb);
long int my_put_nbr_long_int(long int nb);
short int my_put_nbr_short_int(short int nb);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, const char *src);
int my_strlen(char const *str);
int my_put_octal(unsigned int nb);
void my_putstr(char const *str);
int my_put_nbr_hexa_for_pointeur(unsigned long int nb);
int my_strcmp(const char *str1, const char *str2);
char *my_strdup(char const *src);
char **my_str_to_word_array_delim(char *str, char delim);

#endif /* MY_ */
