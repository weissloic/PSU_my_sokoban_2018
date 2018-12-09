/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include "../include/my.h"

void check_victory(t_struct *square_detect, t_read *read_map)
{
    square_detect->number_crate_valid = 0;

    for (int i = 0; i <= square_detect->number_crate; i++) {
        for (int j = 0; j < square_detect->number_valid; j++) {
            if ((square_detect->pos_taby[i] == square_detect->valid_taby[j]) &&
                (square_detect->pos_tabx[i] == square_detect->valid_tabx[j])) {
                square_detect->number_crate_valid++;
                check_victory_two(square_detect, read_map);
            }
        }
    }
}

void check_victory_two(t_struct *square_detect, t_read *read_map)
{
    if (square_detect->number_crate_valid == square_detect->number_valid)
        exit(0);
}

void check_corner(t_struct *square_detect, t_read *read_map)
{
    square_detect->number_corner = 0;

    for (int i = 0; i < square_detect->number_crate; i++) {
        if ((read_map->tab[square_detect->pos_taby[i] + 1]
            [square_detect->pos_tabx[i]]) == '#' &&
            (read_map->tab[square_detect->pos_taby[i]]
            [square_detect->pos_tabx[i] + 1]) == '#')
            square_detect->number_corner++;
        else if ((read_map->tab[square_detect->pos_taby[i] - 1]
            [square_detect->pos_tabx[i]]) == '#' &&
            (read_map->tab[square_detect->pos_taby[i]]
            [square_detect->pos_tabx[i] + 1]) == '#')
            square_detect->number_corner++;
        else if ((read_map->tab[square_detect->pos_taby[i] - 1]
            [square_detect->pos_tabx[i]]) == '#' &&
            (read_map->tab[square_detect->pos_taby[i]]
            [square_detect->pos_tabx[i] - 1]) == '#')
            square_detect->number_corner++;
        check_corner_two(square_detect, read_map, i);
    }
}

void check_corner_two(t_struct *square_detect, t_read *read_map, int i)
{
        if ((read_map->tab[square_detect->pos_taby[i] + 1]
            [square_detect->pos_tabx[i]]) == '#' &&
            (read_map->tab[square_detect->pos_taby[i]]
            [square_detect->pos_tabx[i] - 1]) == '#')
            square_detect->number_corner++;
        if (square_detect->number_corner == square_detect->number_crate)
            exit(1);
}