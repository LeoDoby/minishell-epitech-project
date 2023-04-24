/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** error
*/
#include "my.h"

int crash(int status)
{
    int sig = 0;
    if (WIFSIGNALED(status)){
        sig = WTERMSIG(status);
        if (sig == SIGSEGV && WCOREDUMP(status)){
            my_putstr("Segmentation fault (core dumped)\n");
            return 139;
        }
        if (sig == SIGSEGV){
            my_putstr("Segmentation fault\n");
            return 139;
        }
        if (sig == SIGFPE && WCOREDUMP(status)){
            my_putstr("Floating exception (core dumped)\n");
            return 136;
        }
        if (sig == SIGFPE){
            my_putstr("Floating exception\n");
            return 136;
        }
    }
}

term *other_termin(char *line ,term *term, char **array)
{
    int o;

    if (term->env[0] == NULL){
        if (access(array[0], o) == 0){
            my_execve(array[0], array, term);
        }else {
            my_putstr(my_strcat(array[0],": Command not found.\n"));
        }
        return 0;
    }
    if (other_command(term, array) == 1){
        my_putstr(my_strcat(array[0],": Command not found.\n"));
        exit(0);
    }
    return 0;
}

int not_valid(char *line)
{
    if (line[0] == '\0')
        return 0;
    for (int i = 0; line[i] != '\0'; i++){
        if ((line[i] != ' ' && line[i] != '\t') && line[i] != '\0')
            return 1;
    }
    return 0;
}
