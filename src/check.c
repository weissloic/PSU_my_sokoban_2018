/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include "../include/my.h"

int find_player(t_struct *square_detect, t_read *read_map)
{
    for (int i = 0; i < square_detect->nb_line; i++) {
        for (int j = 0; j < square_detect->nb_cols; j++) {
            if (read_map->tab[i][j] == 'P') {
                square_detect->posx = i;
                square_detect->posy = j;
                square_detect->posx_stock = square_detect->posx;
                square_detect->posy_stock = square_detect->posy;
                read_map->tab[square_detect->posx][square_detect->posy] = ' ';
            }
        }
    }
}

void number_crate(t_struct *square_detect, t_read *read_map)
{
    int m = 0;

    for (int i = 0; i < square_detect->nb_line; i++) {
        for (int j = 0; j < square_detect->nb_cols; j++) {
            if (read_map->tab[i][j] == 'X') {
                square_detect->pos_tabx[m] = j;
                square_detect->pos_taby[m] = i;
                square_detect->pos_tabx_stock[m] = j;
                square_detect->pos_taby_stock[m] = i;
                m++;
            }
        }
    }
}

void count_crate(t_struct *square_detect, t_read *read_map)
{
    int counter = 0;
    int m = 0;

    for (int i = 0; i < square_detect->nb_line; i++) {
        for (int j = 0; j < square_detect->nb_cols; j++) {
            if (read_map->tab[i][j] == 'X') {
                counter++;
                square_detect->number_crate = counter;
            }
        }
    }
}

void valid_pos(t_struct *square_detect, t_read *read_map)
{
    int counter = 0;
    int m = 0;

    for (int i = 0; i < square_detect->nb_line; i++) {
        for (int j = 0; j < square_detect->nb_cols; j++) {
            if (read_map->tab[i][j] == 'O') {
                square_detect->valid_tabx[m] = j;
                square_detect->valid_taby[m] = i;
                m++;
            }
        }
    }
}

void count_valid_pos(t_struct *square_detect, t_read *read_map)
{
    int counter = 0;
    int m = 0;

    for (int i = 0; i < square_detect->nb_line; i++) {
        for (int j = 0; j < square_detect->nb_cols; j++) {
            if (read_map->tab[i][j] == 'O') {
                counter++;
                square_detect->number_valid = counter;
            }
        }
    }
}