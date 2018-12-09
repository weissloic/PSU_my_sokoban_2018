/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include "../include/my.h"

void key_right_two(t_struct *square_detect, t_read *read_map)
{
    if ((read_map->tab[square_detect->posx]
        [square_detect->posy + 2]) == '#' &&
        (read_map->tab[square_detect->posx]
        [square_detect->posy + 1]) == 'X') {
        square_detect->posy == square_detect->posy;
    }
    else if ((read_map->tab[square_detect->posx]
        [square_detect->posy + 2]) == 'X' &&
        (read_map->tab[square_detect->posx]
        [square_detect->posy + 1]) == 'X') {
        square_detect->posx == square_detect->posx;
    }
    else if ((read_map->tab[square_detect->posx]
        [square_detect->posy + 1]) != '#') {
        square_detect->posy += 1;
    }
}

void key_left_two(t_struct *square_detect, t_read *read_map)
{
    if ((read_map->tab[square_detect->posx]
        [square_detect->posy - 2]) == '#' &&
        (read_map->tab[square_detect->posx]
        [square_detect->posy - 1]) == 'X') {
        square_detect->posy == square_detect->posy;
    }
    else if ((read_map->tab[square_detect->posx]
        [square_detect->posy - 2]) == 'X' &&
        (read_map->tab[square_detect->posx]
        [square_detect->posy - 1]) == 'X') {
        square_detect->posx == square_detect->posx;
    }
    else if ((read_map->tab[square_detect->posx]
        [square_detect->posy - 1]) != '#') {
        square_detect->posy -= 1;
    }
}

void key_up_two(t_struct *square_detect, t_read *read_map)
{
    if (read_map->tab[square_detect->posx - 1][square_detect->posy] == '#') {
        square_detect->posx = square_detect->posx;
    }
    else if ((read_map->tab[square_detect->posx - 2]
        [square_detect->posy]) == '#' &&
        (read_map->tab[square_detect->posx - 1]
        [square_detect->posy]) == 'X') {
        square_detect->posx == square_detect->posx;
    }
    else if ((read_map->tab[square_detect->posx - 2]
        [square_detect->posy]) == 'X' &&
        (read_map->tab[square_detect->posx - 1]
        [square_detect->posy]) == 'X') {
        square_detect->posx == square_detect->posx;
    }
    else
        square_detect->posx -= 1;
}

void key_down_two(t_struct *square_detect, t_read *read_map)
{
    if (read_map->tab[square_detect->posx + 1][square_detect->posy] == '#') {
        square_detect->posx = square_detect->posx;
    }
    else if ((read_map->tab[square_detect->posx + 2]
        [square_detect->posy]) == 'X' &&
        (read_map->tab[square_detect->posx + 1]
        [square_detect->posy]) == 'X') {
        square_detect->posx == square_detect->posx;
    }
    else if ((read_map->tab[square_detect->posx + 2]
        [square_detect->posy]) == '#' &&
        (read_map->tab[square_detect->posx + 1]
        [square_detect->posy]) == 'X') {
        square_detect->posx == square_detect->posx;
    }
    else
        square_detect->posx += 1;
}

void key_space(t_struct *square_detect, t_read *read_map)
{
    square_detect->posx = square_detect->posx_stock;
    square_detect->posy = square_detect->posy_stock;
    for (int i = 0; i < square_detect->number_crate; i++) {
        (read_map->tab[square_detect->pos_taby[i]]
        [square_detect->pos_tabx[i]]) = ' ';
        my_strcpy(square_detect->pos_tabx, square_detect->pos_tabx_stock);
        my_strcpy(square_detect->pos_taby, square_detect->pos_taby_stock);
        (read_map->tab[square_detect->pos_taby_stock[i]]
        [square_detect->pos_tabx_stock[i]]) = 'X';
    }
    refresh();
}