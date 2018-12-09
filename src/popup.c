/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "../include/my.h"

int main(int ac, char **av)
{
    t_struct *square_detect = malloc(sizeof(t_struct));
    t_read *read_map = malloc(sizeof(t_read));
    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        how_use_game();
        return (0);
    }
    bsq_function(av[1], square_detect, read_map);
    valid_map(square_detect, read_map);
    count_crate(square_detect, read_map);
    count_valid_pos(square_detect, read_map);
    malloc_one(square_detect, read_map);
    valid_pos(square_detect, read_map);
    number_crate(square_detect, read_map);
    check_error(square_detect, read_map);
    find_player(square_detect, read_map);
    my_sokoban(square_detect, read_map);
    return (0);
}

void check_error(t_struct *square_detect, t_read *read_map)
{
    valid_player(square_detect, read_map);
    valid_pos(square_detect, read_map);
    if (square_detect->number_player != 1)
        exit (84);
    if (square_detect->number_valid != square_detect->number_crate)
        exit (84);
}

void my_sokoban(t_struct *square_detect, t_read *read_map)
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    while (1) {
        print_my_map(square_detect, read_map);
        refresh();
        mvprintw(square_detect->posx, square_detect->posy, "P");
        check_victory(square_detect, read_map);
        check_corner(square_detect, read_map);
        square_detect->ch = getch();
        key_function(square_detect, read_map);
        clear();
    }
}

void malloc_one(t_struct *square_detect, t_read *read_map)
{
    (square_detect->valid_tabx
    = malloc(sizeof(int) * square_detect->number_valid));
    (square_detect->valid_taby =
    malloc(sizeof(int) * square_detect->number_valid));
    square_detect->pos_tabx = malloc(sizeof(int) * square_detect->number_crate);
    square_detect->pos_taby = malloc(sizeof(int) * square_detect->number_crate);
    (square_detect->pos_tabx_stock =
    malloc(sizeof(int) * square_detect->number_crate));
    (square_detect->pos_taby_stock
    = malloc(sizeof(int) * square_detect->number_crate));
}