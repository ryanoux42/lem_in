/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-1-lemin-zacharie.rodde
** File description:
** print_moves.c
*/

#include "../include/libmy.h"

void step_one(int i, lemin *l, room **path)
{
    int decompte = i - 1;

    for (int j = 1; j < i + 1; j++) {
        write(1, "P", 1);
        my_put_nbr(j);
        write(1, "-", 1);
        write(1, path[decompte]->name, my_strlen(path[decompte]->name));
        if (j + 1 != i + 1)
            write(1, " ", 1);
        decompte--;
    }
    write(1, "\n", 1);
}

void step_two(int i, int len_path, lemin *l, room **path)
{
    int decompte = len_path - 1;

    for (int j = i - (len_path - 1); j <= l->nb_ants; j++) {
        write(1, "P", 1);
        my_put_nbr(j);
        write(1, "-", 1);
        write(1, path[decompte]->name, my_strlen(path[decompte]->name));
        if (j + 1 != l->nb_ants + 1)
            write(1, " ", 1);
        decompte--;
    }
    write(1, "\n", 1);
}

void step_three(int i, int len_path, lemin *l, room **path)
{
    int decompte = len_path - 1;

    for (int j = i - (len_path - 1); j <= i; j++) {
        write(1, "P", 1);
        my_put_nbr(j);
        write(1, "-", 1);
        write(1, path[decompte]->name, my_strlen(path[decompte]->name));
        if (j + 1 != i + 1)
            write(1, " ", 1);
        decompte--;
    }
    write(1, "\n", 1);
}

void step_by_step(room **path, lemin* l, int i, int len_path)
{
    int decompte = 0;

    if (i <= len_path) {
        step_one(i, l, path);
    } else if (i >= l->nb_ants) {
        step_two(i, len_path, l, path);
    } else {
        step_three(i, len_path, l, path);
    }
}
