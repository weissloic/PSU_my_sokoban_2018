/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include "../include/my.h"

void key_left(t_struct *square_detect, t_read *read_map)
{
    key_left_two(square_detect, read_map);

    for (int i = 0; i <= square_detect->number_crate; i++) {
        if ((square_detect->pos_taby[i] == square_detect->posx) &&
            (square_detect->pos_tabx[i] == square_detect->posy)
            && (read_map->tab[square_detect->posx]
            [square_detect->posy - 1]) != '#') {
            (read_map->tab[square_detect->pos_taby[i]]
            [square_detect->pos_tabx[i] - 1]) = 'X';
            (read_map->tab[square_detect->pos_taby[i]]
            [square_detect->pos_tabx[i]]) = ' ';
            square_detect->pos_tabx[i] = square_detect->pos_tabx[i] - 1;
        }
    }
    refresh();
}

void key_down(t_struct *square_detect, t_read *read_map)
{
    key_down_two(square_detect, read_map);

    for (int i = 0; i <= square_detect->number_crate; i++) {
        if ((square_detect->pos_taby[i] == square_detect->posx) &&
            (square_detect->pos_tabx[i] == square_detect->posy) &&
            (read_map->tab[square_detect->posx + 1]
            [square_detect->posy]) != '#') {
            (read_map->tab[square_detect->pos_taby[i] + 1]
            [square_detect->pos_tabx[i]]) = 'X';
            (read_map->tab[square_detect->pos_taby[i]]
            [square_detect->pos_tabx[i]]) = ' ';
            square_detect->pos_taby[i] = square_detect->pos_taby[i] + 1;
        }
    }
    refresh();
}

void key_up(t_struct *square_detect, t_read *read_map)
{
    key_up_two(square_detect, read_map);

    for (int i = 0; i <= square_detect->number_crate; i++) {
            if ((square_detect->pos_taby[i] == square_detect->posx) &&
                (square_detect->pos_tabx[i] == square_detect->posy) &&
                (read_map->tab[square_detect->posx - 1]
                [square_detect->posy]) != '#') {
            (read_map->tab[square_detect->pos_taby[i] - 1]
            [square_detect->pos_tabx[i]]) = 'X';
            (read_map->tab[square_detect->pos_taby[i]]
            [square_detect->pos_tabx[i]]) = ' ';
            square_detect->pos_taby[i] = square_detect->pos_taby[i] - 1;
            }
    }
    refresh();
}

void key_right(t_struct *square_detect, t_read *read_map)
{
    key_right_two(square_detect, read_map);

    for (int i = 0; i <= square_detect->number_crate; i++) {
        if ((square_detect->pos_taby[i] == square_detect->posx) &&
            (square_detect->pos_tabx[i] == square_detect->posy) &&
            (read_map->tab[square_detect->posx]
            [square_detect->posy + 1]) != '#') {
            (read_map->tab[square_detect->pos_taby[i]]
            [square_detect->pos_tabx[i] + 1]) = 'X';
            (read_map->tab[square_detect->pos_taby[i]]
            [square_detect->pos_tabx[i]]) = ' ';
            square_detect->pos_tabx[i] = square_detect->pos_tabx[i] + 1;
        }
    }
    refresh();
}

void key_function(t_struct *square_detect, t_read *read_map)
{
    if (square_detect->ch == ' ')
        key_space(square_detect, read_map);
    if (square_detect->ch == KEY_RIGHT)
        key_right(square_detect, read_map);
    if (square_detect->ch == KEY_UP)
        key_up(square_detect, read_map);
    if (square_detect->ch == KEY_DOWN)
        key_down(square_detect, read_map);
    if (square_detect->ch == KEY_LEFT)
        key_left(square_detect, read_map);
}