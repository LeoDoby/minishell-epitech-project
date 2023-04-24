/*
** EPITECH PROJECT, 2022
** MY_STRCAT
** File description:
** a funtion that concatenate two string
*/
#include <stdio.h>
#include "my.h"
char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int z = 0;
    char *re;
    re = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    while (i < my_strlen(dest)){
        re[i] = dest[i];
        i++;
    }
    while (z < my_strlen(src)){
        re[i] = src[z];
        i++;
        z++;
    }
    re[my_strlen(dest) + my_strlen(src)] = '\0';
    return re;
}
