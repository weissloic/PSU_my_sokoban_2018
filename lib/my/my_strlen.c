/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int co = 0;

    while (str[co] != '\0')
        co++;
    return (co);
}