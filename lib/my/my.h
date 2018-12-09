/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my_h
*/

#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef MY_LIST_H_
#define MY_LIST_H_

typedef struct square {
    int nb_cols;
    int nb_line;
    int posy;
    int posx;
    int posx_stock;
    int posy_stock;
    int cratex;
    int cratey;
    int validposx;
    int validposy;
    int number_valid;
    int number_crate;
    int number_player;
    int check_map;
    int ch;
    int *pos_tabx_stock;
    int *pos_taby_stock;
    int *pos_tabx;
    int *pos_taby;
    int *valid_tabx;
    int *valid_taby;
    int number_corner;
    int number_crate_valid;
    int size_sqr;
} t_struct;

typedef struct read {
    int fd;
    struct stat st;
    int size;
    char *buffer;
    char **tab;
    int valeur_read;
    int taille_nbr;
} t_read;

typedef struct Entities
{
    struct square *t_struct;
    struct read *read_map;
} Entities_t;

int my_strlen(char const *str);
char **double_array(char *buffer, t_struct *square_detect);
int buffer_nb_line(char const *buffer);
int buffer_nb_cols(char const *buffer);
int valid_player(t_struct *square_detect, t_read *read_map);
int valid_map(t_struct *square_detect, t_read *read_map);
void malloc_one(t_struct *square_detect, t_read *read_map);
void my_sokoban(t_struct *square_detect, t_read *read_map);
void check_error(t_struct *square_detect, t_read *read_map);
void print_my_map(t_struct *square_detect, t_read *read_map);
void print_all(t_struct *square_detect, t_read *read_map);
void bsq_function(char const *filepath,
t_struct *square_detect, t_read *read_map);
void key_space(t_struct *square_detect, t_read *read_map);
void key_down_two(t_struct *square_detect, t_read *read_map);
void key_up_two(t_struct *square_detect, t_read *read_map);
void key_left_two(t_struct *square_detect, t_read *read_map);
void key_right_two(t_struct *square_detect, t_read *read_map);
void count_valid_pos(t_struct *square_detect, t_read *read_map);
void valid_pos(t_struct *square_detect, t_read *read_map);
void count_crate(t_struct *square_detect, t_read *read_map);
void number_crate(t_struct *square_detect, t_read *read_map);
int find_player(t_struct *square_detect, t_read *read_map);
void check_corner_two(t_struct *square_detect, t_read *read_map, int i);
void check_corner(t_struct *square_detect, t_read *read_map);
void check_victory_two(t_struct *square_detect, t_read *read_map);
void check_victory(t_struct *square_detect, t_read *read_map);
void key_function(t_struct *square_detect, t_read *read_map);
void key_right(t_struct *square_detect, t_read *read_map);
void key_up(t_struct *square_detect, t_read *read_map);
void key_down(t_struct *square_detect, t_read *read_map);
void key_left(t_struct *square_detect, t_read *read_map);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);

#endif