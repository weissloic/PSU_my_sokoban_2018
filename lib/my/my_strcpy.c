/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int co = 0;

    while (src[co] != '\0') {
        dest[co] = src[co];
        co++;
    }
    dest[co] = '\0';
    return (dest);
}