/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** function.c
*/
#include "my.h"

char *search_path(char *tk, char *tmp, term *term)
{
    int i = 0;
    if (term->env[0] == NULL)
        return "no";
    while (my_strcmp(tk, "PATH") != 0 && term->env[i] != 0){
        i++;
        free(tmp);
        if (term->env[i] == 0)
            return "no";
        tmp = my_strdup(term->env[i]);
        tk = strtok(tmp, "=");
    }
}

int my_execve(char *tmp, char **array, term *term)
{
    if (execve(tmp, array, term->env) == -1){
        my_putstr(array[0]);
        my_putstr(": ");
        if (errno == ENOEXEC){
            my_putstr(strerror(errno));
            my_putstr(". Wrong Architecture.\n");
            exit(1);
        }
        my_putstr(strerror(errno));
        my_putstr(".\n");
    }
    exit(1);
}

int other_command(term *term, char **array)
{
    char *tmp = my_strdup(term->env[0]);
    char *tk = strtok(tmp, "=");
    int o = 0;
    if (access(array[0], o) == 0)
        return my_execve(array[0], array, term);
    tk = search_path(tk, tmp, term);
    tk = strtok(NULL, ":");
    while (tk != NULL){
        tmp = my_strdup(tk);
        if (tmp[my_strlen(tmp) - 1] != '/')
            tmp = my_strcat(tk, "/");
        tmp = my_strcat(tmp, array[0]);
        if (access(tmp, o) == 0)
            return my_execve(tmp, array, term);
        tk = strtok(NULL, ":");
    }
    return 1;
}

int builtin(char *tmp, char **array, term *term)
{
    if (my_strcmp(array[0], "cd") == 0){
        my_cd(term, array);
        return 1;
    }
    if (my_strcmp(array[0], "setenv") == 0){
        my_setenv(term, array);
        return 1;
    }
    if (my_strcmp(array[0], "unsetenv") == 0){
        my_unsetenv(term, array[1]);
        return 1;
    }
    if (my_strcmp(array[0], "env") == 0){
        my_env(term);
        return 1;
    }
    if (my_strcmp(array[0], "exit") == 0){
        my_exit();
        return 1;
    } return 0;
}

term *valid_cd(char **array, term *term, int a)
{
    if (array[1][0] == '~'){
        term = home(term);
        getcwd(term->path, term->size_path);
        return term;
    }
    if (access(array[1], a) == 0){
        if (chdir(array[1]) == -1){
            my_putstr(array[1]);
            my_putstr(": ");
            my_putstr(strerror(errno));
            my_putstr(".\n");
        }
        getcwd(term->path, term->size_path);
        return term;
    }
    return term;
}
