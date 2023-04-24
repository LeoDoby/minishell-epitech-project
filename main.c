/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** main.c
*/
#include "my.h"

char **str_to_array(char *str)
{
    char **array;
    char *tmp = my_strdup(str);
    char *tk = strtok(str, " \t");
    int u = 0;

    while (tk != NULL){
        tk = strtok(NULL, " \t");
        u++;
    }
    array = malloc(sizeof(char *) * (u + 1));
    tk = strtok(tmp, " \t");
    for (int i = 0;tk != NULL;i++){
        array[i] = my_strdup(tk);
        tk = strtok(NULL, " \t");
    }
    array[u] = 0;
    return array;
}

term *home(term *term)
{
    char *tmp = my_strdup(term->env[0]);
    char *tk = strtok(tmp, "=");
    int i = 1;

    while (my_strcmp(tk, "HOME") != 0){
        i++;
        tmp = my_strdup(term->env[i]);
        tk = strtok(tmp, "=");
    }
    tk = strtok(NULL, "=");
    chdir(tk);
    return term;
}

int termin(char *line, term *term)
{
    char *tmp = my_strdup(line);
    char **array = str_to_array(tmp);
    pid_t pid;

    if (builtin(tmp, array, term) == 1)
        return 0;
    pid = fork();
    if (the_fork(pid, line, term, array) == 84)
        return 84;
    return 0;
}

int the_fork(pid_t pid, char *line, term *term, char **array)
{
    int status;
    char *path;

    if (pid == -1){
        perror("fork");
        return 84;
    }
    if (pid == 0){
        other_termin(line, term, array);
        return 0;
    } else {
        waitpid(pid, &status, 0);
        crash(status);
        return 0;
    }
}

int main(int argc, char **argv, char **env)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t input;
    term *term = malloc(sizeof(term));
    term->env = env;
    term->path = getcwd(term->path, term->size_path);
    while (1){
        my_putstr("Nya~$");
        input = getline(&line, &len, stdin);
        if (input == -1){
            my_putstr("exit\n");
            return 0;
        }
        line[input - 1] = '\0';
        if (not_valid(line) == 1)
            termin(line, term);
    }
    return 0;
}
