/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** check
*/
#include "my.h"

void replace_that(int i, term *term, char **array)
{
    term->env[i] = my_strcat(array[1], "=");
    if (array[2] == 0)
        return;
    term->env[i] = my_strcat(term->env[i], array[2]);
}

int check_exist(term *term, char **array)
{
    int i = 0;
    char *tk;
    char *tmp;

    if (term->env[0] == NULL)
        return 0;
    tmp = my_strdup(term->env[0]);
    tk = strtok(tmp, "=");
    while (my_strcmp(tk, array[1]) != 0 && term->env[i] != 0){
        i++;
        free(tmp);
        if (term->env[i] == 0)
            return 0;
        tmp = my_strdup(term->env[i]);
        tk = strtok(tmp, "=");
    }
    if (term->env[i] == 0)
        return 0;
    replace_that(i, term, array);
    return 1;
}

int not_valid_env(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (my_chr_isalphanum(str[i]) == 0 && str[i] != '_')
            return 1;
    }
    return 0;
}

int check_all(term *term,char **array, int which)
{
    if (which == 0 && array[1] == 0){
        my_env(term);
        return 0;
    }
    if (which == 1 && not_valid_env(array[1]) == 1){
        my_putstr("setenv: Variable name must ");
        my_putstr("contain alphanumeric characters.\n");
        return 1;
    }
    if (which == 1 && check_exist(term, array) == 1)
        return 1;
    return 2;
}
