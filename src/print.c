/*
** EPITECH PROJECT, 2022
** print.c
** File description:
** print
*/
#include "../include/libmy.h"

int my_pathlen(room **path)
{
    int i = 0;

    while (path[i] != NULL) {
        i++;
    }
    return i;
}

void print_moves(room **path, lemin *l)
{
    int len_path = my_pathlen(path);
    my_putstr("#moves\n");
    for (int i = 1; i < l->nb_ants + len_path; i++) {
        step_by_step(path, l, i, len_path);
    }
}
