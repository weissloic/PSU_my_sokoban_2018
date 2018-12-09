/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int co = 0;

    while (str[co]) {
        my_putchar(str[co]);
        co++;
    }
    return (0);
}