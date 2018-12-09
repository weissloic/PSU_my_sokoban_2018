/*
** EPITECH PROJECT, 2018
** assignement 1
** File description:
** assignement 1
*/

#include "../include/my.h"

void print_my_map(t_struct *square_detect, t_read *read_map)
{
    for (int i = 0; i < square_detect->nb_line; i++) {
        mvprintw(i, 0, read_map->tab[i]);
    }
}

void print_all(t_struct *square_detect, t_read *read_map)
{
    square_detect->nb_cols = buffer_nb_cols(read_map->buffer);
    square_detect->nb_line = buffer_nb_line(read_map->buffer);
}

void bsq_function(char const *filepath,
t_struct *square_detect, t_read *read_map)
{
    read_map->fd = 0;
    read_map->taille_nbr = 0;
    stat(filepath, &read_map->st);
    read_map->size = read_map->st.st_size;
    read_map->fd = open(filepath, O_RDONLY);
    read_map->buffer = malloc(sizeof(char) * read_map->size + 1);
    (read_map->valeur_read =
    read(read_map->fd, read_map->buffer, read_map->size + 1));
    print_all(square_detect, read_map);
    read_map->tab = NULL;
    read_map->tab = malloc(sizeof(char *) * read_map->size + 1);
    for (int i = 0; i < square_detect->nb_line; i++)
        read_map->tab[i] = malloc(sizeof(char) * square_detect->nb_cols + 1);
    read_map->buffer[read_map->size] = '\0';
    read_map->tab = double_array(read_map->buffer, square_detect);
    if (read_map->fd == -1)
        exit(84);
}

void how_use_game(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\t map file representing the warehouse map, containing");
    my_putstr("# for walls, \n\t P for the player, X for boxes and 'O'");
    my_putstr(" for storage locations.\n");
}