/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include "../include/my.h"

char **double_array(char *buffer, t_struct *square_detect)
{
    char **tab = malloc(sizeof(char *) * (square_detect->nb_line + 1));
    int line = 0;
    int cols = 0;

    for (int i = 0; i < square_detect->nb_line; i++) {
        tab[i] = malloc(sizeof(char) * (square_detect->nb_cols + 1));
    }
    for (int j = 0; buffer[j] != '\0'; j++) {
        if (buffer[j] == '\n') {
            line++;
            cols = 0;
        } else {
            tab[line][cols] = buffer[j];
            cols++;
        }
    }
    return (tab);
}

int buffer_nb_line(char const *buffer)
{
    int j = 0;
    int counter = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            j++;
    }
    return (j);
}

int buffer_nb_cols(char const *buffer)
{
    int i = 0;
    int j = 0;

    for (int i = 0; buffer[i] != '\n'; i++) {
        j++;
    }
    return (j);
}

int valid_player(t_struct *square_detect, t_read *read_map)
{
    int counter = 0;

    for (int i = 0; i < square_detect->nb_line; i++) {
        for (int j = 0; j < square_detect->nb_cols; j++) {
            if (read_map->tab[i][j] == 'P') {
                counter++;
                square_detect->number_player = counter;
            }
        }
    }
}

int valid_map(t_struct *square_detect, t_read *read_map)
{
    int counter = 0;
    for (int i = 0; i < square_detect->nb_line; i++) {
        for (int j = 0; j < square_detect->nb_cols; j++) {
            if ((read_map->tab[i][j] != '#') &&
                (read_map->tab[i][j] != 'X') &&
                (read_map->tab[i][j] != 'P') &&
                (read_map->tab[i][j] != 'O') &&
                (read_map->tab[i][j] != ' ') && (read_map->tab[i][j] != '\n')
                && read_map->tab[i][j] != '\0')
                exit (84);
        }
    }
}