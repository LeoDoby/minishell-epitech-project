/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** function.c
*/
#include "my.h"

term *my_cd(term *term, char **array)
{
    int a = 0;
    free(term->path);
    term->path = malloc(1024);
    term->size_path = 1024;
    if (array[1] == 0){
        term = home(term);
        getcwd(term->path, term->size_path);
        return term;
    }
    valid_cd(array, term, a);
    return term;
}

int my_unsetenv(term *term, char *str)
{
    if (term->env[0] == NULL)
        return 0;
    char *tmp = my_strdup(term->env[0]);
    char *tk = strtok(tmp, "=");
    int i = 0;
    for (;my_strcmp(tk, str) != 0 && term->env[i] != 0;i++){
        free(tmp);
        tmp = my_strdup(term->env[i]);
        tk = strtok(tmp, "=");
    }
    i -= 1;
    if (term->env[i] == 0)
        return 0;
    while (term->env[i + 1] != 0){
        term->env[i] = term->env[i + 1];
        i++;
    }
    term->env[i] = 0;
    return 0;
}

void my_env(term *term)
{
    for (int i = 0; term->env[i] != 0;i++){
        my_putstr(term->env[i]);
        my_putchar('\n');
    }
}

int my_setenv(term *term, char **array)
{
    int i = 0;
    char **new_env;
    if (check_all(term, array, 0) == 0)
        return 0;
    if (check_all(term, array, 1) == 1)
        return 1;
    for (; term->env[i] != 0; i++);
    new_env = malloc(sizeof(char *) * (i + 2));
    for (i = 0; term->env[i] != 0; i++)
        new_env[i] = term->env[i];
    if (array[2] == 0){
        new_env[i] = my_strcat(array[1],"=");
        new_env[i + 1] = 0;
        term->env = new_env;
        return 0;
    }
    new_env[i] = my_strcat(my_strcat(array[1], "="),array[2]);
    new_env[i + 1] = 0;
    term->env = new_env;
    return 0;
}

int my_exit(void)
{
    return 0;
}
